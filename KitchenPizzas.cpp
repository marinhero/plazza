//
// KitchenPizzas.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Apr 19 17:51:12 2013 ivan ignatiev
// Last update Fri Apr 19 18:56:47 2013 ivan ignatiev
//

#include "KitchenPizzas.hh"

KitchenPizzas::KitchenPizzas(void) : size_(0)
{
    TRACE(KitchenPizzas::KitchenPizzas, "KitchenPizzas create");
}

KitchenPizzas::KitchenPizzas(KitchenPizzas const &)
{
}

KitchenPizzas &KitchenPizzas::operator=(KitchenPizzas const &)
{
    return (*this);
}

KitchenPizzas::~KitchenPizzas(void)
{
    TRACE(KitchenPizzas::~KitchenPizzas, "KitchenPizzas destroye");
}

void KitchenPizzas::pushPizza(Pizza const &pizza)
{
    TRACE(KitchenPizzas::pushPizza, "Pizza accept");
    MutexScopeLock __locker__(pizzalock_);
    this->pizzas_.push_back(pizza);
    ++this->size_;
}

Pizza &KitchenPizzas::popPizza(void)
{
    TRACE(KitchenPizzas::popPizza, "Pizza go out");
    MutexScopeLock __locker__(pizzalock_);
    Pizza &pizza = * new Pizza(this->pizzas_.back());
    this->pizzas_.pop_back();
    --this->size_;
    return (pizza);
}

int KitchenPizzas::size(void) const
{
    return (this->size_);
}
