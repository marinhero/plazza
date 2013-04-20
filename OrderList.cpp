//
// OrderList.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Sat Apr 20 13:19:32 2013 xiaoyan zhang
// Last update Sat Apr 20 19:04:59 2013 ivan ignatiev
//

#include "OrderList.hh"

int             OrderList::ordernum_ = 0;

OrderList::OrderList(std::list<std::string> const &list)
{
  TRACE(OrderList::OrderList, "create orderlist");
  for (std::list<std::string>::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        std::string type = *it;
        ++it;
        std::string size = *it;
        ++it;
        ++it;
        std::stringstream strtoint(*it);
        ++it;
        int count;
        strtoint >> count;
        for (int i = 0; i < count; ++i)
        {
          this->_v.push_back(&PizzaFactory::createPizza(type, size, OrderList::ordernum_));
        }
    }
    ++OrderList::ordernum_;
}

OrderList::~OrderList()
{
}

int   OrderList::getPizzaCount() const
{
    return (this->_v.size());
}

Pizza   &OrderList::popPizza(void)
{
    Pizza &pizza = this->_v.back()->clone(this->_v.back()->getSize());
    delete this->_v.back();
    this->_v.pop_back();
    return (pizza);
}
