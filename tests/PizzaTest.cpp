//
// PizzaTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:13:50 2013 ivan ignatiev
// Last update Sat Apr 20 18:17:16 2013 ivan ignatiev
//

#include "PizzaFactory.hh"
#include "tests/test.h"

int     main(int argc, char **argv)
{
    Pizza &pizza1 = PizzaFactory::createPizza("margarita", "XXL");
    std::cout << "type : " << pizza1.getStrType() << " " <<  pizza1.getType() <<  "  size : " << pizza1.getStrSize()  << " " << pizza1.getSize() << std::endl;

    Pizza &pizza2 = PizzaFactory::createPizza("americana", "XL");
    std::cout << "type : " << pizza2.getStrType() << " " <<  pizza2.getType() <<  "  size : " << pizza2.getStrSize()  << " " << pizza2.getSize() << std::endl;

    Pizza &pizza3 = PizzaFactory::createPizza("regina", "L");
    std::cout << "type : " << pizza3.getStrType() << " " <<  pizza3.getType() <<  "  size : " << pizza3.getStrSize()  << " " << pizza3.getSize() << std::endl;

    Pizza &pizza4 = PizzaFactory::createPizza("fantasia", "M");
    std::cout << "type : " << pizza4.getStrType() << " " <<  pizza4.getType() <<  "  size : " << pizza4.getStrSize()  << " " << pizza4.getSize() << std::endl;


    return (EXIT_SUCCESS);
}
