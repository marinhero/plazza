//
// Reception.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:28:37 2013 Marin Alcaraz
// Last update Sun Apr 21 00:37:40 2013 Marin Alcaraz
//

#include "Reception.hh"


Reception::Reception()
{
}

Reception::~Reception()
{
}

void    Reception::load_balancer()
{

}

void    Reception::in_business() const
{
    int                 t_id;
    Graphics            win("plazza");
    std::vector<int>    commandsids;

    win.display_menu();
    while (1)
    {
        t_id = win.read_order();
        if (t_id != -1)
            commandsids.push_back(t_id);
        win.display_kitchens();
        win.display_orders();
        win.update();
    }
    win.exit_screen_mode();
}
