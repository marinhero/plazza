//
// PizzaTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:13:50 2013 ivan ignatiev
// Last update Tue Apr 16 15:16:33 2013 ivan ignatiev
//

#include "Pizza.hh"
#include "tests/test.h"

int     main(int argc, char **argv)
{
    Pizza   pizza(Pizza::Margarita, Pizza::XXL);
    printf("Pizza [ size : %d type : %d ] \n", pizza.getSize(), pizza.getType());
    return (EXIT_SUCCESS);
}
