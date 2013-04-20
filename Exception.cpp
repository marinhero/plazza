//
// Exception.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Thu Apr 18 16:53:45 2013 xiaoyan zhang
// Last update Sat Apr 20 00:50:56 2013 Marin Alcaraz
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
