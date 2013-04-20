/*
** PizzaFactory.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Sat Apr 20 14:51:17 2013 ivan ignatiev
** Last update Sat Apr 20 15:01:25 2013 ivan ignatiev
*/

#ifndef PIZZAFACTORY_H_
# define PIZZAFACTORY_H_

# include <map>
# include <string>

# include "Debug.hh"
# include "Pizza.hh"

class PizzaFactory
{
    private:
        static int factory_count_;
        static std::map<std::string, Pizza *>                pizzas_;
        static std::map<std::string, Pizza::TaillePizza>    sizes_;
        static ingr_stlist_t                                ingrs_;

        PizzaFactory(PizzaFactory const &);
        PizzaFactory &operator=(PizzaFactory const &);
    public:
        PizzaFactory(void);

        static void learn(void);

        static void learnSize(std::string const &size, Pizza::TaillePizza);
        static void learnPizza(Pizza &);
        static Pizza &createPizza(std::string const &type, std::string const &size, int);
        static ingr_stlist_t const &ingrList(void);

        static void forget(void);

        ~PizzaFactory(void);
};

#endif /* !PIZZAFACTORY_H_ */
