//
// KitchenInspector.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sun Apr 21 20:26:26 2013 Marin Alcaraz
// Last update Sun Apr 21 20:34:25 2013 Marin Alcaraz
//

#ifndef KITCHENINSPECTOR_H
# define KITCHEINSPECTOR_H

#include    <vector>
#include    "Kitchen.hh"
#include    "Exception.hh"
#include    "Thread.hh"

class KitchenInspector
{
    private:
        bool    threadrun_;

    public:
        KitchenInspector(void);
        ~KitchenInspector();
        int     inspect_stock(std::vector<Kitchen>);
        void    *run(void);
};

#endif
