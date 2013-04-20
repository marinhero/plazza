//
// OrderList.hh for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Sat Apr 20 13:17:03 2013 xiaoyan zhang
// Last update Sat Apr 20 18:53:08 2013 ivan ignatiev
//

#ifndef ORDERLIST_HH_H_
# define ORDERLIST_HH_H_

# include <string>
# include <list>
# include <vector>
# include <sstream>

#include "PizzaFactory.hh"

class	OrderList
{
    static int              ordernum_;
    std::vector<Pizza *>	_v;
    public:
    OrderList(std::list<std::string> const &list);
    ~OrderList();
    int   getPizzaCount() const;
    Pizza	&popPizza();
};

#endif
