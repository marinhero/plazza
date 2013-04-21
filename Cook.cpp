//
// Cook.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sun Apr 21 02:16:07 2013 ivan ignatiev
// Last update Sun Apr 21 19:10:29 2013 ivan ignatiev
//

# include "Cook.hh"

CondVariable        Cook::cond_;

Cook::Cook(int cooktime, KitchenPizzas &kitchenpizzas, KitchenStock &kitchenstock)
    : cooktime_(cooktime), busy_(false), threadrun_(true), pizza_(NULL),
    kitchenstock_(kitchenstock), kitchenpizzas_(kitchenpizzas),
    thread_(* new Thread(*this))
{
    TRACE(Cook::Cook, "Cook is ready");
}

Cook &Cook::operator=(Cook const &)
{
    return (*this);
}

Cook::~Cook(void)
{
    TRACE(Cook::~Cook, "Cook is destroyed");
    this->threadrun_    = false;
    Cook::cond_.unfreeze_all();
    delete &this->thread_;
}

void    Cook::cookPizza(void)
{
    TRACE(Cook::cookPizza, "Wake up one of cooks");
    Cook::cond_.unfreaze_one();
}

bool    Cook::isBusy(void) const
{
    return (this->busy_);
}

void    *Cook::run(void)
{
    TRACE(Cook::run, "Cook starts working");
    while (this->threadrun_)
    {
        try
        {
            if (!this->threadrun_)
                return (NULL);
            TRACE(Cook::run, "Begin cooking pizza");
            this->pizza_ = &this->kitchenpizzas_.popPizza();
            this->kitchenstock_.takeIngrList(this->pizza_->getIngr());
            this->busy_ = true;
            sleep(this->cooktime_ * this->pizza_->getCookTime());
            TRACE(Cook::run, "Finish cook a pizza");
            this->busy_ = false;
            delete this->pizza_;
            this->pizza_ = NULL;
        }
        catch(std::exception *e)
        {
            TRACE(Cook::run, "No more pizzas to cook");
            Cook::cond_.freeaze();
        }
    }
    return (NULL);
}

Pizza   const   &Cook::getCookingPizza() const
{
    if (pizza_ != NULL)
        return (*pizza_);
    throw new std::exception();
}
