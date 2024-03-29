//
// Exception.hh for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Thu Apr 18 16:48:09 2013 xiaoyan zhang
// Last update Sun Apr 21 22:04:13 2013 ivan ignatiev
//

#ifndef EXCEPTION_HH_H_
# define EXCEPTION_HH_H_

#include <string>
#include <exception>

class	Exception : public std::exception
{
protected:
  std::string	_what;
public:
  Exception(std::string const &error) throw();
  virtual const char *what(void) const throw();
  virtual ~Exception(void) throw();
};

class		OrderException : public Exception
{
public:
  OrderException(std::string const &error) throw();
  virtual ~OrderException() throw();
};

class		ParamException : public Exception
{
public:
  ParamException(std::string const &error) throw();
  virtual ~ParamException() throw();
};

class		BadFileException : public Exception
{
public:
  BadFileException(std::string const &error) throw();
  virtual ~BadFileException() throw();
};

#endif
