//
// Ingredient.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Wed Apr 17 14:57:14 2013 xiaoyan zhang
// Last update Wed Apr 17 15:44:48 2013 xiaoyan zhang
//

#include "Ingredient.hh"

Ingredient::Ingredient(std::string const &type)
{
  this->_type = type;
  this->createIngList();
}

Ingredient::~Ingredient()
{}

const std::list<std::string>	&Ingredient::getIngList() const
{
  return (this->_ingList);
}

void			Ingredient::createIngList()
{
  if (this->_type.compare("margarita") == 0)
    {
      this->_ingList.push_back("doe");
      this->_ingList.push_back("tomato");
      this->_ingList.push_back("gruyere");
    }
  else if (this->_type.compare("regina") == 0)
    {
      this->_ingList.push_back("doe");
      this->_ingList.push_back("tomato");
      this->_ingList.push_back("gruyere");
      this->_ingList.push_back("ham");
      this->_ingList.push_back("mushrooms");
    }
  else if (this->_type.compare("americana") == 0)
    {
      this->_ingList.push_back("doe");
      this->_ingList.push_back("tomato");
      this->_ingList.push_back("gruyere");
      this->_ingList.push_back("steak");
    }
  else if (this->_type.compare("fantasia") == 0)
    {
      this->_ingList.push_back("doe");
      this->_ingList.push_back("tomato");
      this->_ingList.push_back("eggplant");
      this->_ingList.push_back("goat cheese");
      this->_ingList.push_back("cheif love");
    }
}
