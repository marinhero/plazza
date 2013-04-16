//
// parser.hh for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Mon Apr 15 21:41:20 2013 xiaoyan zhang
// Last update Tue Apr 16 13:10:19 2013 xiaoyan zhang
//

#ifndef PARSER_HH_H_
# define PARSER_HH_H_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstring>

class				Order
{
private:
  std::list<std::string>	_list;

public:
  Order(std::istream &flow);
  ~Order();
  std::list<std::string>	getOrder();
  void		put_order_in_list(std::istream &flow);
  int		skipSpaces(std::istream &flow);
  int		getEnd(std::istream &flow);
  void		putTailBack(char *s, int n, int size, std::istream &flow);
  int		getType(std::istream &flow);
  int		getSize(std::istream &flow);
  int		getNumber(std::istream &flow);
  int		getX(std::istream &flow);
  int		getRealNumber(std::istream &flow);
};

#endif
