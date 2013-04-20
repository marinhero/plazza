//
// Graphics.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Apr 19 23:54:54 2013 Marin Alcaraz
// Last update Sat Apr 20 01:06:32 2013 Marin Alcaraz
//

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include    <string>
#include    <ncurses.h>
#include    <iostream>
#include    <fstream>
#include    <string>
#include    <sstream>
#include    <vector>
#include    "Exception.hh"
#include    "Kitchen.hh"
#include    "Order.hh"

class   Graphics
{
    private:
        std::string     name;


    public:
        Graphics(std::string);
        ~Graphics();
        void    init_screen_mode(void) const;
        void    display_menu(void) const;
        void    output(const std::string) const;
        void    read_order(void) const;
        void    display_widgets(std::vector<Kitchen>) const;
        void    update(void) const;
        void    exit_screen_mode(void) const;
};

#endif /* GRAPHICS_H */
