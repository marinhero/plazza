//
// Reception.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:28:37 2013 Marin Alcaraz
// Last update Sat Apr 20 11:00:18 2013 Marin Alcaraz
//

#include "Reception.hh"


Reception::Reception()
{
}

Reception::~Reception()
{
}

void    Reception::display()
{
    Graphics win("Menu");

    win.init_screen_mode();
    win.display_menu();
    while (1)
    {
        win.update();
        win.read_order();
        win.update();
    }
    win.exit_screen_mode();
}
