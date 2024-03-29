//
// parser_test.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Tue Apr 16 11:31:41 2013 xiaoyan zhang
// Last update Fri Apr 19 19:48:35 2013 ivan ignatiev
//

#include "Order.hh"
# include <iostream>
# include <sstream>

int		main()
{

//  Order	order(std::cin);
    std::istringstream &source = * new std::istringstream("regina XXL x6;\n");
    Order   order(static_cast<std::istream &>(source));
    try
    {
        order.parse();
    }
    catch (OrderException *e)
    {
        std::cerr << "Error: " << e->what() << std::endl;
        std::cerr << "-------" << std::endl;
    }
    order.dump();
    return (0);
}
