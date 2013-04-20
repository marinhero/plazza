//
// OrderList.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:13:50 2013 ivan ignatiev
// Last update Sat Apr 20 18:32:45 2013 ivan ignatiev
//


#include "Order.hh"
#include "OrderList.hh"
#include "tests/test.h"

int     main(int argc, char **argv)
{
    Order order(std::cin);
    try
    {
        order.parse();
        order.dump();
        OrderList ol(order.getOrder());
        while (ol.getPizzaCount())
        {
            Pizza &pizza = ol.popPizza();
            std::cout << pizza << std::endl;
        }
    }
    catch (std::exception *e)
    {

    }
    return (EXIT_SUCCESS);
}
