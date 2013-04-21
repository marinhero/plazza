//
// Cook.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sun Apr 21 02:16:07 2013 ivan ignatiev
// Last update Sun Apr 21 15:47:25 2013 ivan ignatiev
//

# include "Cook.hh"

Cook::Cook(int cooktime, KitchenPizzas &kitchenpizzas, KitchenStock &kitchenstock)
    : cooktime_(cooktime), busy_(false), threadrun_(true), pizza_(NULL),
    kitchenstock_(kitchenstock), kitchenpizzas_(kitchenpizzas),
    thread_(* new Thread(*this))
{

}

Cook &Cook::operator=(Cook const &)
{
    return (*this);
}

Cook::~Cook(void)
{
    this->threadrun_ = false;
    delete &this->thread_;
}

void    Cook::cookPizza(void)
{
    // Cond Var signal
}

bool    Cook::isBusy(void) const
{
    return (busy_);
}

void    *Cook::run(void)
{
    while (this->threadrun_)
    {
        try
        {
            // CondVar
            if (!this->threadrun_)
                return (NULL);
            /*this->pizza_ = &this->kitchenpizzas_.popPizza();
            this->kitchenstock_.takeIngrList(this->pizza_->getIngr());
            this->busy_ = true;
            sleep(this->cooktime_ * this->pizza_->getCookTime());*/
        }
        catch(std::exception *e)
        {

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
