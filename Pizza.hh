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

# include <iostream>
# include <string>
# include <map>
# include <unistd.h>

# include "Debug.hh"

typedef std::map<std::string, int>  ingr_stlist_t;

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
    private:
        Pizza(void);

        int         cooktime_;
        TypePizza   type_;
        TaillePizza size_;
        int         ordernum_;
        static bool inited_;
        static std::map<TaillePizza, std::string> sizes_;
    public:

        Pizza(TypePizza type, TaillePizza size, int ordernum);
        Pizza(Pizza const &pizza);

        static void init(void);
        virtual Pizza const &operator=(Pizza const &pizza);

        TypePizza   getType(void) const;
        TaillePizza getSize(void) const;
        int         getOrderNum(void) const;
        int         getCookTime(void) const;
        virtual std::string const &getStrType(void) const = 0;
        std::string const &getStrSize(void) const;

        void        setCookTime(int);
        void        setType(TypePizza);
        void        setSize(TaillePizza);
        void        setOrderNum(int);

        virtual ingr_stlist_t const &getIngr(void) const = 0;
        virtual Pizza &clone(void) const = 0;

        virtual ~Pizza(void);
};

class Margarita : public Pizza
{
    private:
        ingr_stlist_t       ingrs_;
        std::string         strtype_;

        Margarita(void);
        void                initIngr(void);
    public:
        Margarita(Pizza::TaillePizza size, int ordernum = 0);
        Margarita(Margarita const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(void) const;

        ~Margarita(void);
};

class Regina : public Pizza
{
    private:
        ingr_stlist_t       ingrs_;
        std::string         strtype_;

        Regina(void);
        void                initIngr(void);
    public:
        Regina(Pizza::TaillePizza size, int ordernum = 0);
        Regina(Regina const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(void) const;

        ~Regina(void);
};

class Americana : public Pizza
{
    private:
        ingr_stlist_t       ingrs_;
        std::string         strtype_;

        Americana(void);
        void                initIngr(void);
    public:
        Americana(Pizza::TaillePizza size, int ordernum = 0);
        Americana(Americana const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(void) const;

        ~Americana(void);
};

class Fantasia : public Pizza
{
    private:
        ingr_stlist_t       ingrs_;
        std::string         strtype_;

        Fantasia(void);
        void                initIngr(void);
    public:
        Fantasia(Pizza::TaillePizza size, int ordernum = 0);
        Fantasia(Fantasia const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(void) const;

        ~Fantasia(void);
};

std::ostream &operator<<(std::ostream &ost, Pizza const &);

#endif /* !PIZZA_H_ */
