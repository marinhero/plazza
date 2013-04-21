//
// KitchenStock.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sun Apr 21 11:55:01 2013 ivan ignatiev
// Last update Sun Apr 21 18:31:34 2013 ivan ignatiev
//

# include "KitchenStock.hh"

KitchenStock::KitchenStock(void)
    : threadrun_(true), regenthread_(* new Thread(* this))
{
    this->initIngr(PizzaFactory::ingrList());
}

KitchenStock::KitchenStock(KitchenStock const &kitchenstock)
    : threadrun_(true), regenthread_(* new Thread(* this))
{
    this->initIngr(kitchenstock.getIngrList());
}

KitchenStock &KitchenStock::operator=(KitchenStock const &kitchenstock)
{
    if (this != &kitchenstock)
    {
        this->initIngr(kitchenstock.getIngrList());
    }
    return (*this);
}

KitchenStock::~KitchenStock(void)
{
    this->threadrun_ =false;
    delete &this->regenthread_;
}

void    KitchenStock::initIngr(ingr_stlist_t const &allingrs)
{
    MutexScopeLock __locker__(this->stocklock_);
    ingr_stlist_t::const_iterator it = allingrs.begin();
    for (;it != allingrs.end(); ++it)
    {
        this->ingrs_[it->first] = 5;
    }
}

ingr_stlist_t const &KitchenStock::getIngrList(void) const
{
    return (this->ingrs_);
}

void            KitchenStock::takeIngrList(ingr_stlist_t const &ingrs)
{
    MutexScopeLock  __locker__(this->stocklock_);
    ingr_stlist_t::const_iterator       it = ingrs.begin();
    for (;it != ingrs.end(); ++it)
    {
        this->ingrs_[it->first] -= it->second;
    }
}

void            *KitchenStock::run(void)
{
    while (this->threadrun_)
    {
        TRACE(KitchenStock::run, "Regenerate kitchen stock + 1");
        this->stocklock_.lock();
        ingr_stlist_t::iterator       it = this->ingrs_.begin();
        for (;it != this->ingrs_.end(); ++it)
        {
            ++this->ingrs_[it->first];
        }
        this->stocklock_.unlock();
        sleep(1);
    }
    return (NULL);
}
