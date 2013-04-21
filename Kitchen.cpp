//
// Kitchen.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 14:20:17 2013 ivan ignatiev
// Last update Sun Apr 21 19:46:51 2013 ivan ignatiev
//

#include "Kitchen.hh"

Kitchen::Kitchen(void)
{

}

Kitchen::~Kitchen(void)
{
    if (this->pid_ == 0)
    {
        while (!this->cooks_.empty())
        {
            delete this->cooks_.back();
            this->cooks_.pop_back();
        }
    }
}

Kitchen::Kitchen(Kitchen const &)
{

}

Kitchen::Kitchen(int cookscount, int cooktime)
 : cookscount_(cookscount), cooktime_(cooktime)
{
    this->pid_ = fork();
    if (this->pid_ == 0)
    {
        for (int i = 0; i < cookscount_; ++i)
        {
            this->cooks_.push_back(new Cook(this->cooktime_, this->kitchenpizzas_, this->kitchenstock_));
        }
    }
}

bool    Kitchen::acceptPizza(Pizza const &pizza)
{
    if (this->pid_ == 0)
    {
        if (this->kitchenpizzas_.size() > (this->cookscount_ * 2))
            return (false);
        try
        {
            this->kitchenpizzas_.pushPizza(pizza);
            Cook::cookPizza();
        }
        catch (std::exception *e)
        {
            return (false);
        }
        return (true);
    }
    return (true);
}

