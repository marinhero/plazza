//
// Order.hh for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Mon Apr 15 21:41:20 2013 xiaoyan zhang
// Last update Thu Apr 18 16:58:01 2013 xiaoyan zhang
//

#ifndef ORDER_HH_H_
# define ORDER_HH_H_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include "Exception.hh"

class				Order
{
private:
  std::list<std::string>	_list;
  std::istream			&_flow;

  void		putOrderInList(std::istream &flow);
  int		skipSpaces(std::istream &flow);
  int		endFlow(std::istream &flow);
  int		getInstr(std::istream &flow);
  int		getSep(std::istream &flow);
  void		putTailBack(char *s, int n, int size, std::istream &flow);
  int		getType(std::istream &flow);
  int		getSize(std::istream &flow);
  int		getNumber(std::istream &flow);
  int		getX(std::istream &flow);
  int		getRealNumber(std::istream &flow);
public:
  Order(std::istream &flow);
  ~Order();
  std::list<std::string>	&getOrder();
  void				parse();
  void				dump() const;
};

#endif
