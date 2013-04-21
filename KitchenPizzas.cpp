//
// KitchenPizzas.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Apr 19 17:51:12 2013 ivan ignatiev
// Last update Sun Apr 21 15:47:52 2013 ivan ignatiev
//

#include "KitchenPizzas.hh"

KitchenPizzas::KitchenPizzas(void)
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
    this->pizzas_.push_back(&pizza.clone());
}

Pizza &KitchenPizzas::popPizza(void)
{
    TRACE(KitchenPizzas::popPizza, "Pizza go out");
    MutexScopeLock __locker__(pizzalock_);
    if (this->pizzas_.size() <= 0)
        throw new std::exception();
    Pizza &pizza = * this->pizzas_.back();
    this->pizzas_.pop_back();
    return (pizza);
}

int KitchenPizzas::size(void) const
{
    return (this->pizzas_.size());
}
