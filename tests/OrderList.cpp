//
// OrderList.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:13:50 2013 ivan ignatiev
// Last update Sun Apr 21 00:10:36 2013 ivan ignatiev
//


#include "Order.hh"
#include "tests/test.h"

int     main(int argc, char **argv)
{
    try
    {
        Order &order = * new Order(std::cin);
        order.dump();
        std::cout << "Proccess order " << order.getOrderNumber() << " : " << std::endl;
        while (order.getPizzaCount())
        {
            Pizza &pizza = order.popPizza();
            std::cout << "Pizza goes to cook: " << pizza << std::endl;
            delete &pizza;
        }
        delete &order;
    }
    catch (std::exception *e)
    {

    }
    return (EXIT_SUCCESS);
}
