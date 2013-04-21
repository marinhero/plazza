//
// Kitchen.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 14:20:17 2013 ivan ignatiev
// Last update Sun Apr 21 21:50:22 2013 ivan ignatiev
//

#include "Kitchen.hh"

int                     Kitchen::knum_ = 0;

Kitchen::Kitchen(void)
{

}

Kitchen::~Kitchen(void)
{
    if (this->pid_ == 0)
    {
        while (!this->cooks_.empty())
        {
            delete this->cooks_.back();
            this->cooks_.pop_back();
        }
        this->ipipe_.close();
        this->opipe_.close();
    } else
    {
        this->ipipe_.close();
        this->opipe_.close();
        unlink(this->pipefilein_.c_str());
        unlink(this->pipefileout_.c_str());
    }
}

Kitchen::Kitchen(Kitchen const &)
{

}

Kitchen::Kitchen(int cookscount, int cooktime, long refreshtime)
 : cookscount_(cookscount), cooktime_(cooktime)
{
    std::ostringstream       oss;
    oss << "/tmp/plazzakitchenin" << Kitchen::knum_;
    this->pipefilein_ = oss.str();
    oss.clear();
    oss << "/tmp/plazzakitchenout" << Kitchen::knum_;
    this->pipefileout_ = oss.str();
    this->kitchenstock_.setRefrechTime(refreshtime);
    ++Kitchen::knum_;
    this->pid_ = fork();
    if (this->pid_ == 0)
    {
        this->prepareCooks();
        this->ipipe_.open(this->pipefileout_.c_str(), std::istream::in);
        this->opipe_.open(this->pipefilein_.c_str(), std::ostream::out);
    }
    else
    {
        if (mkfifo(this->pipefileout_.c_str(), 0666) != 0)
            throw new std::exception();
        if (mkfifo(this->pipefilein_.c_str(), 0666) != 0)
            throw new std::exception();
        this->ipipe_.open(this->pipefilein_.c_str(), std::istream::in);
        this->opipe_.open(this->pipefileout_.c_str(), std::ostream::out);
    }
}

void        Kitchen::prepareCooks(void)
{
    for (int i = 0; i < cookscount_; ++i)
    {
        this->cooks_.push_back(new Cook(this->cooktime_, this->kitchenpizzas_, this->kitchenstock_));
    }
}

bool    Kitchen::acceptPizza(Pizza const &pizza)
{
    if (this->pid_ == 0)
    {
        if (this->kitchenpizzas_.size() > this->cookscount_)
            return (false);
        try
        {
            this->kitchenpizzas_.pushPizza(pizza);
            Cook::cookPizza();
        }
        catch (std::exception *e)
        {
            return (false);
        }
        return (true);
    }
    return (true);
}

