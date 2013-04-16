//
// parser.cpp for plazza in /home/zhang_x//c++/project/plazza/plazza
// 
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
// 
// Started on  Mon Apr 15 21:40:58 2013 xiaoyan zhang
// Last update Tue Apr 16 13:11:20 2013 xiaoyan zhang
//

#include "parser.hh"

Order::Order(std::istream &flow)
{
  put_order_in_list(flow);
}

Order::~Order()
{

}

std::list<std::string>	Order::getOrder()
{
  return (this->_list);
}

void		Order::put_order_in_list(std::istream &flow)
{
  if (!skipSpaces(flow))
    {
      if (!getType(flow))
	throw ;
      if (!getSize(flow))
	throw ;
      if (!getNumber(flow))
	throw ;
      if (!getEnd(flow))
	throw ;
    }
  else
    flow.get();
}

int		Order::skipSpaces(std::istream &flow)
{
  char		c;

  flow.read(&c, 1);
  while (c == ' ' || c == '\t')
    {
      flow.read(&c, 1);
    }
  flow.putback(c);
  if (c == 10)
    return (1);
  return (0);
}

int		Order::getEnd(std::istream &flow)
{
  char		array[1];

  skipSpaces(flow);
  flow.read(array, 1);
  if (array[0] == '\n')
    {
      _list.push_back(";");
      return (1);
    }
  flow.putback(array[0]);
  return (0);
}

void		Order::putTailBack(char *s, int n, int size, std::istream &flow)
{
  int		l = size;
  
  for(int i = l - 1; i >= l - n; --i)
    {
      flow.putback(s[i]);
    }
}

int		Order::getType(std::istream &flow)
{
  std::string	orders[4] = {"regina", "fantasia", "margarita", "americaine"};
  char		array[10];

  skipSpaces(flow);
  flow.read(array, 10);
  for (int i = 0; i < 4; ++i)
    {
      if (orders[i].compare(0, 10, array, orders[i].size()) == 0)
	{
	  _list.push_back(orders[i]);
	  putTailBack(array, 10 - orders[i].size(), 10, flow);
	  return (1);
	}
    }
  putTailBack(array, 10, 10, flow);
  return (0);
}


int		Order::getSize(std::istream &flow)
{
  std::string	sizes[5] = {"S", "M", "L", "XL", "XXL"};
  char		array[3];

  skipSpaces(flow);
  flow.read(array, 3);
  for (int i = 0; i < 5; ++i)
    {
      if (sizes[i].compare(0, 3, array, sizes[i].size()) == 0)
	{
	  _list.push_back(sizes[i]);
	  putTailBack(array, 3 - sizes[i].size(), 3, flow);
	  return (1);
	}
    }
  putTailBack(array, 3, 3, flow);
  return (0);
}

int		Order::getNumber(std::istream &flow)
{
  if (!getX(flow))
    return (1);
  if (!getRealNumber(flow))
    return (1);
  return (0);
}

int		Order::getX(std::istream &flow)
{
  char		array[1];

  skipSpaces(flow);
  flow.read(array, 1);
  if (array[0] == 'x')
    {
      _list.push_back("x");
      return (1);
    }
  flow.putback(array[0]);
  return (0);
}

int		Order::getRealNumber(std::istream &flow)
{
  std::string num = "";
  char c;

  skipSpaces(flow);
  flow.read(&c, 1);
  if (c >= '0' && c <= '9')
    num += c;
  else
    {
      flow.putback(c);
      throw ;
      return (0);
    }
  flow.read(&c, 1);
  while (c >= '0' && c <= '9')
  {
    num += c;
    flow.read(&c, 1);
  }
  flow.putback(c);
  if (num.size() > 0 && num != "-")
    {
      _list.push_back(num);
      return (1);
    }
  throw ;
  return (0);
}
