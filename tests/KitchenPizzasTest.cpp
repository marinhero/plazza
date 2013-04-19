//
// KitchenPizzasTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Thu Apr 18 19:04:58 2013 ivan ignatiev
// Last update Fri Apr 19 18:57:05 2013 ivan ignatiev
//

# include "KitchenPizzas.hh"
# include "tests/test.h"

int     main(void)
{
    KitchenPizzas pizzaslist;

    try {
        Pizza &receivedpizza = * new Pizza(Pizza::Margarita, Pizza::XXL);
        pizzaslist.pushPizza( receivedpizza );
        delete &receivedpizza;
        std::cout << "Pizzas count : " << pizzaslist.size() << std::endl;
        Pizza &cookpizza = pizzaslist.popPizza();
        std::cout << "Pizza : [ type : " << cookpizza.getType() << " size :"  << cookpizza.getSize() << "] " << std::endl;
        delete &cookpizza;
    } catch (std::exception *e)
    {
        std::cerr << e->what() <<std::endl;
    }
    return (EXIT_SUCCESS);
}
