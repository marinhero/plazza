//
// OrderList.cpp for plazza in /home/zhang_x//plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Sat Apr 20 13:19:32 2013 xiaoyan zhang
// Last update Sat Apr 20 18:09:07 2013 xiaoyan zhang
//

#include "OrderList.hh"

OrderList::OrderList(std::list<std::string> const &list)
{
  for (std::list<std::string>::iterator it = list.begin(); it != list.end(); ++it)
    {
      _v.push_back(PizzaFactory::createPizza())
    }

}

OrderList::~OrderList()
{
}
