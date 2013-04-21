//
// main.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:31:22 2013 Marin Alcaraz
// Last update Sun Apr 21 22:38:03 2013 Marin Alcaraz
//

#include "Reception.hh"

template <class T>
T   parse(const char *in)
{
    T out;
    std::string     numstr(in);

    std::stringstream ss(numstr);
    ss >> out;
    return (out);
}

int     main(int ac, char **av)
{
  int   a, b, c;

  if (ac != 4)
       std::cout << "Usage: ./plazza mult cooks refresh_rate" << std::endl;
  else
  {
      a = parse<int>(av[1]);
      b = parse<int>(av[2]);
      c = parse<int>(av[3]);

      if (a <= 0 && b <= 0 && c <= 0)
          return (0);
      Reception plazza(parse<int>(av[1]),
              parse<int>(av[2]), parse<int>(av[3]));
      try
      {
          plazza.in_business();
      }
      catch (std::exception *e)
      {
          std::cout << e->what() << std::endl;
      }
  }
  return (0);
}
