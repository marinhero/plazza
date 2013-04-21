//
// main.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:31:22 2013 Marin Alcaraz
// Last update Sun Apr 21 20:11:28 2013 Marin Alcaraz
//

#include "Reception.hh"

int     main()
{

  Reception plazza;

  try
  {
      plazza.in_business();
  }
  catch (std::exception *e)
  {
      std::cout << e->what() << std::endl;
  }
}
