//
// OrderList.hh for plazza in /home/zhang_x//plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Sat Apr 20 13:17:03 2013 xiaoyan zhang
// Last update Sat Apr 20 18:02:29 2013 xiaoyan zhang
//

#ifndef ORDERLIST_HH_H_
# define ORDERLIST_HH_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "PizzaFactory.hh"

class	OrderList
{
  std::vector<Pizza &>	_v;
public:
  OrderList(std::list<std::string> const &list);
  ~OrderList();
  Pizza	&popPizza();
};

#endif
