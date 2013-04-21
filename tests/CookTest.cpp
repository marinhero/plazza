//
// CookTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sun Apr 21 14:41:44 2013 ivan ignatiev
// Last update Sun Apr 21 19:13:50 2013 ivan ignatiev
//

# include "Cook.hh"
# include "./tests/test.h"

#include <vector>

int     main(void)
{
    KitchenPizzas   kp;
    KitchenStock    ks;

    std::vector<Cook*> cooks;

    cooks.push_back(new  Cook(2, kp, ks));
    cooks.push_back(new  Cook(2, kp, ks));
    cooks.push_back(new  Cook(2, kp, ks));

    kp.pushPizza(  PizzaFactory::createPizza("margarita", "XXL", 0) );
    kp.pushPizza(  PizzaFactory::createPizza("fantasia", "XXL", 0) );

    sleep(20);

    kp.pushPizza(  PizzaFactory::createPizza("fantasia", "XXL", 0) );

    Cook::cookPizza();
    sleep(10);

    return (EXIT_SUCCESS);
}
