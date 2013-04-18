//
// reception.cpp for plazza in /home/hero/Dropbox/EPITECH/II/C++/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:28:37 2013 Marin Alcaraz
// Last update Wed Apr 17 16:11:06 2013 Marin Alcaraz
//

#include "reception.hh"


Reception::Reception()
{
}

Reception::~Reception()
{
}

void    Reception::display()
{
    char    order[1024];

    initscr();
    printw("-----------------------------------\n");
    printw("|           The Plaza             |\n");
    printw("|                                 |\n");
    printw("|   PIZZA               SIZE      |\n");
    printw("|                                 |\n");
    printw("|                                 |\n");
    printw("| Regina            S M L XL XXL  |\n");
    printw("| Fantasia          S M L XL XXL  |\n");
    printw("| Margarita         S M L XL XXL  |\n");
    printw("| Americaine        S M L XL XXL  |\n");
    printw("|                                 |\n");
    printw("|                                 |\n");
    printw("|                                 |\n");
    printw("|  Special price for Epitech!     |\n");
    printw("|                                 |\n");
    printw("|  What would you like to order?  |\n");
    printw("|                                 |\n");
    printw("-----------------------------------\n");
    refresh();
    printw("pizza_prompt> ");
    scanw(" %s", order);
    refresh();
    getch();
    endwin();
}
