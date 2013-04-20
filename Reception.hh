//
// Reception.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:24:50 2013 Marin Alcaraz
// Last update Sat Apr 20 23:52:40 2013 Marin Alcaraz
//

#ifndef RECEPTION_HH
# define RECEPTION_HH

#include "Graphics.hh"
#include "Kitchen.hh"
#include <vector>

class   Reception
{
    public:
        Reception();
        ~Reception();
        void    in_business(void) const;
        void    load_balancer();
};

#endif /* RECEPTION_HH */
