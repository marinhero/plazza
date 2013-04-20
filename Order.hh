//
// Order.hh for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Mon Apr 15 21:41:20 2013 xiaoyan zhang
// Last update Sat Apr 20 23:57:23 2013 ivan ignatiev
//

#ifndef ORDER_HH_H_
# define ORDER_HH_H_

# include <iostream>
# include <string>
# include <vector>
# include <sstream>

# include "PizzaFactory.hh"
# include "Exception.hh"

class				Order
{
private:
  std::vector<std::string>	    _list;
  std::istream			        &_flow;
  static int                    ordernum_;
  int                           num_;
  std::vector<Pizza *>	        _v;

  int		skipSpaces();
  int		endFlow();
  int		getInstr();
  int		getSep();
  void		putTailBack(char *s, int n, int size);
  char      *lowerCase(char *s, int size);
  int		getType();
  int		getSize();
  int		getNumber();
  int		getX();
  int		getRealNumber();
  void      parse();
  void      makePizzaList(void);

  Order(void);
  Order(Order const &);
  Order &operator=(Order const &);
public:
  Order(std::istream &flow);
  ~Order(void);

  void				dump(void) const;
  int               getPizzaCount(void) const;
  int               getOrderNumber(void) const;

  Pizza	&popPizza();
};

#endif
