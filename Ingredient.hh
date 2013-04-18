//
// Ingredient.hh for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Wed Apr 17 14:52:54 2013 xiaoyan zhang
// Last update Wed Apr 17 15:34:49 2013 xiaoyan zhang
//

#ifndef INGREDIENT_HH_H_
# define INGREDIENT_HH_H_

#include <iostream>
#include <string>
#include <list>

class	Ingredient
{
  std::list<std::string>	_ingList;
  std::string			_type;

public:
  Ingredient(std::string const & type);
  ~Ingredient();
  const std::list<std::string>	&getIngList() const;
  void				createIngList();
};

#endif
