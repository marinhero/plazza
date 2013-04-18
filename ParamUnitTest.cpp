//
// main.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza/test
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Thu Apr 18 15:04:45 2013 xiaoyan zhang
// Last update Thu Apr 18 15:48:34 2013 xiaoyan zhang
//

#include "Param.hh"

int		main(int ac, char **av)
{
  Param	param(ac, av);

  try
    {
      param.start();
    }
  catch (ParamException *e)
    {
      std::cerr << "Error : " << e->what() << std::endl;
    }
  return (0);
}
