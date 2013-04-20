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

# include <cstdlib>
# include <time.h>

# include <map>
# include <vector>
# include <string>

# include "ResourceLock.hh"
# include "Pizza.hh"
# include "KitchenPizzas.hh"

typedef std::vector<bool>           cooks_stlist_t;
typedef std::map<std::string, int>  ingr_stlist_t;

class Kitchen
{
    private:
        int                 pid_;
        int                 cookscount_;
        int                 cooktime_;

        cooks_stlist_t          cooks_status_;
        ingr_stlist_t             ingr_status_;

        Kitchen(void);
        Kitchen(Kitchen const &kitchen);
        Kitchen const &operator=(Kitchen const &);
    public:
        Kitchen(int cookscount, int cooktime);

        bool    acceptPizza(Pizza const &);
        int     librePlaces(void) const;
        int     getCooksCount(void) const;

        void    update(void);

        cooks_stlist_t const    &getCookStatus(void) const;
        ingr_stlist_t const     &getStockStatus(void) const;

        ~Kitchen(void);
};

#endif /* !KITCHEN_HH_ */