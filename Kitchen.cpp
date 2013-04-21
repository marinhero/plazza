//
// Kitchen.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 14:20:17 2013 ivan ignatiev
// Last update Sun Apr 21 14:43:57 2013 Marin Alcaraz
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
    (void) kitchen;
}

Kitchen::Kitchen(int cookscount, int cooktime)
 : cookscount_(cookscount), cooktime_(cooktime)
{
    for (int i = 0; i < cookscount; ++i)
        this->cooks_status_.push_back(rand() % 2);

    this->ingr_status_["ananas"] = 5;
    this->ingr_status_["ognion"] = 5;
    this->ingr_status_["tomato"] = 5;
}

bool    Kitchen::acceptPizza(Pizza const &pizza)
{
    (void) pizza;
    TRACE(Kitchen::acceptPizza, "Pizza accepted");
    return (rand() % 2 == 0);
}

