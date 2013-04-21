//
// Graphics.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Apr 19 23:54:54 2013 Marin Alcaraz
// Last update Sun Apr 21 22:12:52 2013 Marin Alcaraz
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
        void    init_wins(void);
        void    init_panels(void);
        void    init_scroll(void);
        void    display_menu(void) const;
        void    output(int, const std::string) const;
        std::string     read_order(void) const;
        void    display_kitchens(std::vector<Kitchen *>) const;
        void    display_orders() const;
        void    update(void) const;
        void    exit_screen_mode(void) const;
        void    wipe(char *) const; //Sorru it is necessary
        void    clear(int);
};

#endif /* GRAPHICS_H */
