//
// TalkTest.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sun Apr 21 18:10:14 2013 Marin Alcaraz
// Last update Sun Apr 21 19:14:05 2013 Marin Alcaraz
//

#include "Talk.hh"

int     main()
{
    try
    {
    Talk t("testers"); //Construction test
    }
    catch (std::exception *e)
    {
        std::cout << e->what() << std::endl;
    }
    return (0);
}
