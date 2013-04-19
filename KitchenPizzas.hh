/*
** KitchenPizzas.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Apr 19 13:42:15 2013 ivan ignatiev
** Last update Fri Apr 19 13:47:29 2013 ivan ignatiev
*/

#ifndef KITCHENPIZZAS_HH_
# define KITCHENPIZZAS_HH_

# include <vector>

# include "Pizza.hh"
# include "ResourceLock.hh"

class KitchenPizzas
{
    private:
        int     size_;

        Mutex   pizzalock_;
        std::vector<Pizza> pizzas_;

        KitchenPizzas &operator=(KitchenPizzas const &);
        KitchenPizzas(KitchenPizzas const &);
    public:
        KitchenPizzas(void);

        void        pushPizza(Pizza const &);
        Pizza       &popPizza(void);

        int         size(void) const;

        ~KitchenPizzas(void);
};

#endif /* !KITCHENPIZZAS_HH_ */
