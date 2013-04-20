//
// Order.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by xiaoyan zhang
// Login   <zhang_x@epitech.net>
//
// Started on  Mon Apr 15 21:40:58 2013 xiaoyan zhang
// Last update Sun Apr 21 00:30:36 2013 ivan ignatiev
//

#include "Order.hh"

int             Order::ordernum_ = 0;

Order::Order(std::istream &flow) : _flow(flow)
{
    if (flow.bad())
        throw (new OrderException("Bad input stream"));

    this->num_ =  ++Order::ordernum_;
    this->parse();
    this->makePizzaList();
}

Order::Order(void) : _flow(* new std::istringstream())
{
}

Order &Order::operator=(Order const &)
{
    return (*this);
}

Order::Order(Order const &) : _flow(* new std::istringstream())
{
}

Order::~Order(void)
{
    while (!this->_v.empty())
    {
        delete this->_v.back();
        this->_v.pop_back();
    }
}

int   Order::getPizzaCount() const
{
    return (this->_v.size());
}

Pizza   &Order::popPizza(void)
{
    Pizza &pizza = this->_v.back()->clone();
    delete this->_v.back();
    this->_v.pop_back();
    return (pizza);
}

void	Order::parse()
{
    while (!endFlow())
    {
        if (!skipSpaces())
        {
            getInstr();
            getSep();
        }
        else
            _flow.get();
    }
}

void    Order::makePizzaList(void)
{
  for (std::vector<std::string>::const_iterator it = _list.begin(); it != _list.end(); ++it)
    {
        std::string type = *it;
        ++it;
        std::string size = *it;
        ++it;
        ++it;
        std::stringstream strtoint(*it);
        ++it;
        int count;
        strtoint >> count;
        for (int i = 0; i < count; ++i)
        {
          this->_v.push_back(&PizzaFactory::createPizza(type, size, this->num_));
        }
    }
}

int     Order::getOrderNumber(void) const
{
    return (this->num_);
}

int		Order::endFlow()
{
  char		c;

  if (!skipSpaces())
  {
      if ((c = _flow.get()) == '#' || _flow.fail() || _flow.eof())
          return (1);
      _flow.putback(c);
  }
  return (0);
}


int		Order::getInstr()
{
    if (getType())
    {
        if (getSize())
        {
            if (!getNumber())
                return (0);
            return (1);
        }
    }
    throw (new OrderException("Not found good instruction"));
    return (0);
}

int		Order::skipSpaces()
{
    char		c;

    _flow.read(&c, 1);
    while (c == ' ' || c == '\t')
    {
        _flow.read(&c, 1);
    }
    _flow.putback(c);
    if (c == 10)
        return (1);
    return (0);
}

int		Order::getSep()
{
  char		array[1];

  skipSpaces();
  _flow.read(array, 1);
  if (array[0] == '\n' || array[0] == ';')
    {
      _list.push_back(";");
      return (1);
    }
  _flow.putback(array[0]);
  return (0);
}

void		Order::putTailBack(char *s, int n, int size)
{
  int		l = size;

  for(int i = l - 1; i >= l - n; --i)
      _flow.putback(s[i]);
}

char    *Order::lowerCase(char *s, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A') + 'a';
    }
    return (s);
}

int		Order::getType()
{
  std::string	orders[4] = {"regina", "fantasia", "margarita", "americaine"};
  char		array[10];
  char      cmparray[10];

  skipSpaces();
  _flow.read(array, 10);
  putTailBack(array, 10, 10);
 _flow.read(cmparray, 10);

  for (int i = 0; i < 4; ++i)
    {
        if (orders[i].compare(0, 10, lowerCase(cmparray, 10), orders[i].size()) == 0)
        {
            _list.push_back(orders[i]);
            putTailBack(array, 10 - orders[i].size(), 10);
            return (1);
        }
    }
  putTailBack(array, 10, 10);
  throw (new OrderException("Not Found Type"));
  return (0);
}


int		Order::getSize()
{
  std::string	sizes[5] = {"S", "M", "L", "XL", "XXL"};
  char		array[3];

  skipSpaces();
  _flow.read(array, 3);
  for (int i = 0; i < 5; ++i)
    {
        if (sizes[i].compare(0, 3, array, sizes[i].size()) == 0)
        {
            _list.push_back(sizes[i]);
            putTailBack(array, 3 - sizes[i].size(), 3);
            return (1);
        }
    }
  putTailBack(array, 3, 3);
  throw (new OrderException("Not Found Size"));
  return (0);
}

int		Order::getNumber()
{
  if (!getX())
    return (1);
  if (!getRealNumber())
    return (1);
  return (0);
}

int		Order::getX()
{
  char		array[1];

  skipSpaces();
  _flow.read(array, 1);
  if (array[0] == 'x')
    {
      _list.push_back("x");
      return (1);
    }
  _flow.putback(array[0]);
  throw (new OrderException("Not Found x"));
  return (0);
}

int		Order::getRealNumber()
{
  std::string num = "";
  char c;

  skipSpaces();
  _flow.read(&c, 1);
  if (c >= '1' && c <= '9')
      num += c;
  else
  {
      _flow.putback(c);
      throw (new OrderException("First number is not good"));
      return (0);
  }
  _flow.read(&c, 1);
  while (c >= '0' && c <= '9')
  {
    num += c;
    _flow.read(&c, 1);
  }
  _flow.putback(c);
  if (num.size() > 0 && num != "-")
  {
      _list.push_back(num);
      return (1);
  }
  throw (new OrderException("Not A Good Number"));
  return (0);
}

void		Order::dump() const
{
  for(std::vector<Pizza *>::const_iterator it = _v.begin(); it != _v.end(); ++it)
    std::cout << **it <<  std::endl;
}
