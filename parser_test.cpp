//
// main.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Tue Apr 16 11:31:41 2013 xiaoyan zhang
// Last update Tue Apr 16 17:01:23 2013 xiaoyan zhang
//

#include "parser.hh"

int		main()
{
  Order	order(std::cin);

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
