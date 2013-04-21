/*
** Kitchen.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Tue Apr 16 14:21:49 2013 ivan ignatiev
** Last update Tue Apr 16 14:23:54 2013 ivan ignatiev
*/

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <vector>
# include <string>

# include "Cook.hh"

class Kitchen
{
    private:
        int                 pid_;
        int                 cookscount_;
        int                 cooktime_;

        KitchenPizzas       kitchenpizzas_;
        KitchenStock        kitchenstock_;

        std::vector<Cook *> cooks_;

        Kitchen(void);
        Kitchen(Kitchen const &kitchen);

    public:
        Kitchen(int cookscount, int cooktime);
        ~Kitchen(void);

        bool    acceptPizza(Pizza const &);
};

#endif /* !KITCHEN_HH_ */
