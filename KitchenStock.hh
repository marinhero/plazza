/*
** KitchenStock.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Tue Apr 16 14:51:15 2013 ivan ignatiev
** Last update Tue Apr 16 14:51:39 2013 ivan ignatiev
*/

#ifndef KITCHENSTOCK_HH_
# define KITCHENSTOCK_HH_

# include "PizzaFactory.hh"
# include "ResourceLock.hh"
# include "Thread.hh"

class KitchenStock : public IThreaded
{
    private:
        ingr_stlist_t   ingrs_;
        bool            threadrun_;

        Thread          &regenthread_;
        Mutex           stocklock_;

        void initIngr(ingr_stlist_t const &);
    public:
        KitchenStock(void);
        KitchenStock(KitchenStock const &);
        KitchenStock &operator=(KitchenStock const &);

        ingr_stlist_t const &getIngrList(void) const;
        void                takeIngrList(ingr_stlist_t const &);
        void                *run(void);

        ~KitchenStock(void);
};

#endif /* !KITCHENSTOCK_HH_ */
