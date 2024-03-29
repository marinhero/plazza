//
// Exception.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Thu Apr 18 16:53:45 2013 xiaoyan zhang
// Last update Sun Apr 21 22:04:15 2013 ivan ignatiev
//

#include "Exception.hh"

Exception::Exception(const std::string & msg) throw() : _what(msg)
{
}

Exception::~Exception(void) throw()
{}

const char	*Exception::what(void) const throw()
{
  return (this->_what.data());
}

ParamException::ParamException(std::string const &msg) throw(): Exception(msg)
{
}

ParamException::~ParamException() throw()
{}

OrderException::OrderException(std::string const &msg) throw(): Exception(msg)
{
}

OrderException::~OrderException() throw()
{}

BadFileException::BadFileException(std::string const &msg) throw(): Exception(msg)
{
}

BadFileException::~BadFileException() throw()
{}
