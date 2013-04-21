//
// main.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:31:22 2013 Marin Alcaraz
// Last update Sun Apr 21 23:35:02 2013 ivan ignatiev
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
  if (ac != 4)
       std::cout << "Usage: ./plazza mult cooks refresh_rate" << std::endl;
  else
  {
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
}
