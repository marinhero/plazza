//
// OrderList.hh for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Wed Apr 17 12:58:58 2013 xiaoyan zhang
// Last update Wed Apr 17 17:09:29 2013 xiaoyan zhang
//

#ifndef ORDERLIST_HH_H
# define ORDERLIST_HH_H

#include "Order.hh"
#include "Ingredient.hh"

class	OrderList
{
  std::list<std::string>	_list;
  std::string			_type;
  std::list<std::string>	_ingredient;
  std::string			_size;
  std::string			_number;
  int				_time;
  int				_multi;
  int				_cookTimes;

public:
  OrderList(std::list<std::string> const &list, int multi);
  ~OrderList();
  const std::string			&getType() const;
  const std::list<std::string>		&getIngredient() const;
  int					&getSize() const;
  const std::string			&getNumber() const;
  int					getCookTimes() const;
  void					setType();
  void					setIngredient();
  void					setSize();
  void					setNumber();
  void					setCookTime();
};

#endif
