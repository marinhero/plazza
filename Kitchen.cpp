//
// Kitchen.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 14:20:17 2013 ivan ignatiev
// Last update Fri Apr 19 20:16:52 2013 ivan ignatiev
//

#include "Kitchen.hh"

Kitchen::Kitchen()
{
    srand(time(NULL));
}

Kitchen::~Kitchen()
{

}

Kitchen::Kitchen(Kitchen const &kitchen)
{

}

Kitchen::Kitchen(int cookscount)
 : cookscount_(cookscount)
{
    for (int i = 0; i < cookscount; ++i)
        this->cooks_status_.push_back(rand() % 2);

    this->ingr_status_["ananas"] = 5;
    this->ingr_status_["ognion"] = 5;
    this->ingr_status_["tomato"] = 5;
}

Kitchen const &Kitchen::operator=(Kitchen const &kitchen)
{

}

bool    Kitchen::acceptPizza(Pizza const &pizza)
{
    TRACE(Kitchen::acceptPizza, "Pizza accepted");
    return (rand() % 2 == 0);
}

int     Kitchen::librePlaces(void) const
{
    return (rand() % this->cookscount_);
}

cooks_stlist_t const    &Kitchen::getCookStatus(void) const
{
    return (this->cooks_status_);
}

ingr_stlist_t const     &Kitchen::getStockStatus(void) const
{
    return (this->ingr_status_);
}

int Kitchen::getCooksCount(void) const
{
    return (this->cookscount_);
}


