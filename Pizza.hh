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

# include <string>
# include <map>

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

        static std::map<TaillePizza, std::string> sizes_;

        Pizza(TypePizza type, TaillePizza size);
        Pizza(Pizza const &pizza);
        virtual Pizza const &operator=(Pizza const &pizza);

        TypePizza   getType(void) const;
        TaillePizza getSize(void) const;
        int         getCookTime(void) const;
        virtual std::string const &getStrType(void) const = 0;
        std::string const &getStrSize(void) const;

        void        setCookTime(int);
        void        setType(TypePizza);
        void        setSize(TaillePizza);

        virtual ingr_stlist_t const &getIngr(void) const = 0;
        virtual Pizza &clone(TaillePizza) const = 0;

        ~Pizza(void);
    private:
        Pizza(void);
        void        init();

        int         cooktime_;
        TypePizza   type_;
        TaillePizza size_;
};

class Margarita : public Pizza
{
    private:
        ingr_stlist_t       ingrs_;
        std::string         strtype_;

        Margarita(void);
        void                initIngr(void);
    public:
        Margarita(Pizza::TaillePizza size);
        Margarita(Margarita const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(Pizza::TaillePizza) const;

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
        Regina(Pizza::TaillePizza size);
        Regina(Regina const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(Pizza::TaillePizza) const;

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
        Americana(Pizza::TaillePizza size);
        Americana(Americana const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(Pizza::TaillePizza) const;

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
        Fantasia(Pizza::TaillePizza size);
        Fantasia(Fantasia const &);

        virtual std::string const &getStrType(void) const;
        virtual ingr_stlist_t   const &getIngr(void) const;
        virtual Pizza           &clone(Pizza::TaillePizza) const;

        ~Fantasia(void);
};

#endif /* !PIZZA_H_ */
