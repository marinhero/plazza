//
// main.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Tue Apr 16 11:31:41 2013 xiaoyan zhang
// Last update Tue Apr 16 11:36:54 2013 xiaoyan zhang
//

#include "parser.hh"

int		main()
{
  Order	order(std::cin);

  std::list<std::string>	s = order.getOrder();
  for(std::list<std::string>::iterator it = s.begin(); it != s.end(); ++it)
    if (*it == "\n")
      std::cout << "New line" << std::endl; 
    else
      std::cout << "'" << *it << "'" <<  std::endl;
  return (0);
}
