//
// Reception.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:24:50 2013 Marin Alcaraz
// Last update Sun Apr 21 21:59:57 2013 Marin Alcaraz
//

#ifndef RECEPTION_HH
# define RECEPTION_HH

#include "Graphics.hh"
#include "Kitchen.hh"
#include "Order.hh"
#include "Thread.hh"
#include <vector>

class   Reception : public IThreaded
{
    private:
        std::vector<Kitchen*>       kitchens;
        int                         multiplier;
        int                         cooks;
        int                         refresh;
        Thread                      &inspecthread_;


    public:
        Reception(int, int, int);
        ~Reception();
        void    *run();
        void    in_business(void);
        int     request_order(std::string, Graphics&);
        int     load_balancer(Pizza const &);
};

#endif /* RECEPTION_HH */
