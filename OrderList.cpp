//
// OrderList.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Wed Apr 17 14:43:41 2013 xiaoyan zhang
// Last update Wed Apr 17 17:11:00 2013 xiaoyan zhang
//

#include "OrderList.hh"

OrderList::OrderList(std::list<std::string> const &list, int multi)
{
  this->_list = list;
  this->_multi = multi;
  setType();
  setIngredient();
  setSize();
  setNumber();
}

OrderList::~OrderList()
{
}

const std::string	&OrderList::getType() const
{
  return (this->_type);
}

const std::list<std::string>	&OrderList::getIngredient() const
{
  return (this->_ing);
}

int			&OrderList::getSize() const
{
  return (this->_size);
}

const std::string	&OrderList::getNumber() const
{
  return (this->_number);
}

int			OrderList::getCookTimes() const
{
  return (this->_cookTime);
}

void			OrderList::setType()
{
  std::list<std::string>	list = this->_list;

  this->_type = list.front();
}

void			OrderList::setIngredient()
{
  Ingredient			ing(this->_type);

  std::list<std::string>	l = ing.getIngList();
  this->_ingredient = l;
}

void			OrderList::setSize()
{
  
}

void			OrderList::setNumber()
{

}

void			OrderList::setCookTime()
{
  
}
