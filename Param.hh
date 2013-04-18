//
// Param.hh for plazza in /home/zhang_x//c++/project/plazza/plazza/test
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Thu Apr 18 14:49:35 2013 xiaoyan zhang
// Last update Thu Apr 18 16:58:19 2013 xiaoyan zhang
//

#ifndef PARAM_HH_H
# define PARAM_HH_H

#include <iostream>
#include <string>
#include <sstream>
#include "Exception.hh"

class	Param
{
private:
  int		_ac;
  char		**_av;
public:
  Param(int, char **);
  ~Param();
  void	start();
  bool	checkNumber(std::string const &str);
  int	checkDot(std::string const &str);
  bool	checkMultiplier(std::string const &str);
};

#endif
