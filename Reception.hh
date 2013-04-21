//
// Reception.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:24:50 2013 Marin Alcaraz
// Last update Sun Apr 21 14:38:30 2013 Marin Alcaraz
//

#ifndef RECEPTION_HH
# define RECEPTION_HH

#include "Graphics.hh"
#include "Kitchen.hh"
#include "Order.hh"
#include <vector>

class   Reception
{
    private:
        std::vector<Kitchen>    kitchens;

    public:
        Reception();
        ~Reception();
        void    in_business(void);
        int     request_order(std::string, Graphics&);
        int     load_balancer(Pizza const &);
};

#endif /* RECEPTION_HH */
