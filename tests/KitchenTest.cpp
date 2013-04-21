//
// KitchenTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:13:50 2013 ivan ignatiev
// Last update Sun Apr 21 19:48:30 2013 ivan ignatiev
//

#include "Kitchen.hh"
#include "tests/test.h"
# include <vector>

int     main(void)
{
    std::vector<Kitchen *> kitchen;

    for (int i = 0; i < 10; ++i)
    {
        kitchen.push_back(new Kitchen(5, 2));
    }

    Pizza &pizza =  PizzaFactory::createPizza("margarita", "XXL", 0);
    int     i = 0;
    while (!kitchen[i]->acceptPizza(pizza) && i < 10) ++i;
    delete &pizza;

    while (!kitchen.empty())
    {
        delete kitchen.back();
        kitchen.pop_back();
    }

    return (EXIT_SUCCESS);
}
