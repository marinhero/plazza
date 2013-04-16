/*
** Pizza.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Tue Apr 16 15:01:48 2013 ivan ignatiev
** Last update Tue Apr 16 15:07:24 2013 ivan ignatiev
*/

#ifndef PIZZA_H_
# define PIZZA_H_

class Pizza
{
    public:
        enum TypePizza
        {
            Regina = 1,
            Margarita = 2,
            Americaine = 4,
            Fantasia = 8
        };

        enum TaillePizza
        {
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16
        };

        Pizza(TypePizza type, TaillePizza size);
        Pizza(Pizza const &pizza);
        Pizza const &operator=(Pizza const &pizza);

        TypePizza   getType(void) const;
        TaillePizza getSize(void) const;

        ~Pizza(void);
    private:
        Pizza(void);
        TypePizza   type_;
        TaillePizza size_;
};

#endif /* !PIZZA_H_ */
