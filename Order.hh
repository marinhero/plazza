//
// Order.hh for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Mon Apr 15 21:41:20 2013 xiaoyan zhang
// Last update Fri Apr 19 19:34:12 2013 ivan ignatiev
//

#ifndef ORDER_HH_H_
# define ORDER_HH_H_

#include <iostream>
#include <string>
#include <list>

#include "Exception.hh"

class				Order
{
private:
  std::list<std::string>	    _list;
  std::istream			        &_flow;

  void		putOrderInList();
  int		skipSpaces();
  int		endFlow();
  int		getInstr();
  int		getSep();
  void		putTailBack(char *s, int n, int size);
  int		getType();
  int		getSize();
  int		getNumber();
  int		getX();
  int		getRealNumber();
public:
  Order(std::istream &flow);
  ~Order();
  std::list<std::string>	&getOrder();
  void				parse();
  void				dump() const;
};

#endif
