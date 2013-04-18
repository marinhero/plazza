//
// IngredientUnitTest.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Wed Apr 17 15:40:13 2013 xiaoyan zhang
// Last update Wed Apr 17 15:45:49 2013 xiaoyan zhang
//

#include "Ingredient.hh"

int		main()
{
  Ingredient	v("fantasia");
  std::list<std::string>	l;

  l = v.getIngList();
  for (std::list<std::string>::iterator it = l.begin(); it != l.end(); ++it)
    std::cout << *it << "-->";
  std::cout << "\n"; 
}
