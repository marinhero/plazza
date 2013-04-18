//
// Param.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza/test
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Thu Apr 18 15:00:47 2013 xiaoyan zhang
// Last update Thu Apr 18 15:50:25 2013 xiaoyan zhang
//

#include "Param.hh"

ParamException::ParamException(std::string const &str) : _what(str)
{
}

const char	*ParamException::what(void) const throw()
{
  return (this->_what.c_str());
}

ParamException::~ParamException() throw()
{}

Param::Param(int ac, char **av)
{
  this->_ac = ac;
  this->_av = av;
}

Param::~Param()
{}

void		Param::start()
{
  if (this->_ac != 4)
    {
      std::cout << "Usage : ./plazza multiplier nm_cooks millseconds" << std::endl;
    }
  else
    {
      if (checkMultiplier(_av[1]))
	{
	  for (int i = 2; i < _ac; ++i)
	    {
	      if (checkNumber(_av[i]) == false)
		{
		  throw (new ParamException("It is not a number"));
		}
	    }
	}
      else
	throw (new ParamException("Multiplier is not good"));
    }
}

int		Param::checkDot(std::string const &str)
{
  int		pos;

  pos = 0;
  for (int i = 0; i < (int)str.size(); ++i)
    {
      pos = i;
      if (str[i] == '.')
	return (pos);
    }
  return (pos);
}

bool		Param::checkMultiplier(std::string const &str)
{
  int		pos;

  if (pos = checkDot(str))
    {
      if (str[pos - 1] != '0')
	return (false);
      return (true);
    }
  else
    return (checkNumber(str));
}

bool		Param::checkNumber(std::string const &s)
{
  for (int i = 0; i < (int)s.length(); ++i)
    {
      if (!(s[i] >= '0' && s[i] <= '9'))
        {
          return (false);
        }
    }
  return (true);
}
