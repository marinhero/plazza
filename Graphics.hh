//
// Graphics.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Apr 19 23:54:54 2013 Marin Alcaraz
// Last update Sat Apr 20 17:26:15 2013 Marin Alcaraz
//

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include    <string>
#include    <ncurses.h>
#include    <iostream>
#include    <fstream>
#include    <string>
#include    <algorithm>
#include    <sstream>
#include    <vector>
#include    <panel.h>
#include    "Exception.hh"
#include    "Kitchen.hh"
#include    "Order.hh"

#define     MENU 0
#define     KITCHENS 1
#define     ORDERS 2

class   Graphics
{
    private:
        std::string     name;
        WINDOW          *my_wins[3];
        PANEL           *my_panels[3];

    public:
        Graphics(std::string);
        ~Graphics();
        void    display_menu(void) const;
        void    output(int, const std::string) const;
        void    read_order(void) const;
        void    display_widgets(std::vector<Kitchen>) const;
        void    update(void) const;
        void    exit_screen_mode(void) const;
        void    wipe(char *) const; //Sorru it is necessary
};

#endif /* GRAPHICS_H */
