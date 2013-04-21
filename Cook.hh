/*
** Cook.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Tue Apr 16 14:52:20 2013 ivan ignatiev
** Last update Tue Apr 16 14:52:39 2013 ivan ignatiev
*/

#ifndef COOK_H_
# define COOK_H_

# include "PizzaFactory.hh"
# include "KitchenPizzas.hh"
# include "KitchenStock.hh"
# include "ResourceLock.hh"
# include "Thread.hh"

class Cook : public IThreaded
{
    private:
        int             cooktime_;
        bool            busy_;
        bool            threadrun_;

        Pizza           *pizza_;
        KitchenStock    &kitchenstock_;
        KitchenPizzas   &kitchenpizzas_;
        Thread          &thread_;

        Cook            &operator=(Cook const &cook);
    public:
        Cook(int cooktime, KitchenPizzas &kitchenpizzas,
                KitchenStock &kitchenstock);

        void            *run(void);

        void            cookPizza(void);
        bool            isBusy(void) const;
        Pizza   const   &getCookingPizza(void) const;

        ~Cook(void);
};

#endif /* !COOK_H_ */
