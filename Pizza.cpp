//
// Pizza.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:07:45 2013 ivan ignatiev
// Last update Tue Apr 16 15:13:32 2013 ivan ignatiev
//

#include "Pizza.hh"

Pizza::Pizza(void)
{
}

Pizza::~Pizza(void)
{
}

Pizza::Pizza(Pizza::TypePizza type, Pizza::TaillePizza size)
    : type_(type), size_(size)
{

}

Pizza::Pizza(Pizza const &pizza)
    : type_(pizza.getType()), size_(pizza.getSize())
{

}

Pizza const &Pizza::operator=(Pizza const &pizza)
{
    if (this != &pizza)
    {
        this->type_ = pizza.getType();
        this->size_ = pizza.getSize();
    }
    return (*this);
}

Pizza::TypePizza Pizza::getType(void) const
{
    return (this->type_);
}

Pizza::TaillePizza Pizza::getSize(void) const
{
    return (this->size_);
}
