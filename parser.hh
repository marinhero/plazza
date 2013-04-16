//
// parser.hh for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Mon Apr 15 21:41:20 2013 xiaoyan zhang
// Last update Tue Apr 16 16:20:03 2013 xiaoyan zhang
//

#ifndef PARSER_HH_H_
# define PARSER_HH_H_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstring>

class		OrderException : public std::exception
{
private:
  std::string	_what;
public:
  OrderException(std::string const &error);
  virtual const char *what(void) const throw();
  virtual ~OrderException() throw();
};

class				Order
{
private:
  std::list<std::string>	_list;
  std::istream			&_flow;

  void		putOrderInList(std::istream &flow);
  int		skipSpaces(std::istream &flow);
  int		endFlow(std::istream &flow);
  int		getInstr(std::istream &flow);
  int		getSep(std::istream &flow);
  void		putTailBack(char *s, int n, int size, std::istream &flow);
  int		getType(std::istream &flow);
  int		getSize(std::istream &flow);
  int		getNumber(std::istream &flow);
  int		getX(std::istream &flow);
  int		getRealNumber(std::istream &flow);
public:
  Order(std::istream &flow);
  ~Order();
  std::list<std::string>	&getOrder();
  void				parse();
  void				dump() const;
};

#endif
