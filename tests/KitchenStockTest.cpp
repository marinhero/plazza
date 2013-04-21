//
// KitchenStockTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sun Apr 21 12:41:10 2013 ivan ignatiev
// Last update Sun Apr 21 13:44:43 2013 ivan ignatiev
//

#include "KitchenStock.hh"
#include "./tests/test.h"

int     main(void)
{
    int             i = 0;
    KitchenStock    ks;
    while ( i < 10)
    {
        ingr_stlist_t const  &ing = ks.getIngrList();
        ingr_stlist_t::const_iterator it = ing.begin();
        for (;it != ing.end(); ++it)
        {
            std::cout << it->first << " : " << it->second << " , ";
        }
        std::cout << std::endl;
        ++i;
        sleep(1);
    }
    Pizza &cookpizza = PizzaFactory::createPizza("margarita", "XXL", 0);
    ks.takeIngrList(cookpizza.getIngr());
    ingr_stlist_t const  &ing = ks.getIngrList();
    ingr_stlist_t::const_iterator it = ing.begin();
    for (;it != ing.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << " , ";
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}
