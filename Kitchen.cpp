//
// Kitchen.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 14:20:17 2013 ivan ignatiev
// Last update Sun Apr 21 23:20:06 2013 ivan ignatiev
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
    }
    else
    {
        this->opipe_ << "QUIT" << std::endl;
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
    this->kitchenstock_.setRefrechTime(refreshtime);
    this->preparePipes();
    this->pid_ = fork();
    if (this->pid_ == 0)
    {
        this->prepareCooks();
        this->prepareCmd();
        this->opipe_.open(this->pipefilein_.c_str(), std::ostream::out);
        this->ipipe_.open(this->pipefileout_.c_str(), std::istream::in);
        this->run();
    }
    else
    {
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

void        Kitchen::prepareCmd(void)
{
    this->cmds_["QUIT"] = &Kitchen::quit;
    this->cmds_["REPORT"] = &Kitchen::report;
    this->cmds_["PIZZA"] = &Kitchen::pizza;
    this->cmds_["ACTIVE"] = &Kitchen::check_active;
}

void        Kitchen::check_active(void)
{
    for (std::vector<Cook *>::iterator it = this->cooks_.begin();
            it != this->cooks_.end();
            ++it)
    {
        if ((*it)->isBusy())
        {
            this->opipe_ << "ACTIVE" << std::endl;
        }
    }
    this->opipe_ << "DISACTIVE" << std::endl;
}

void        Kitchen::quit(void)
{
    try
    {
        while (!this->cooks_.empty())
        {
            delete this->cooks_.back();
            this->cooks_.pop_back();
        }
        this->ipipe_.close();
        this->opipe_.close();
    }
    catch (std::exception *e)
    {
    }
    exit(0);
}

void        Kitchen::report(void)
{
    this->opipe_ << "KITCHEN #" << this->num_ << std::endl;
    this->opipe_ << "PIZZAS WAIT : " << this->kitchenpizzas_.size() << std::endl;
    this->opipe_ << "COOKS : ";
    int     i  = 0;
    for (std::vector<Cook *>::iterator it = this->cooks_.begin();
            it != this->cooks_.end();
            ++it, ++i)
    {
        if ((*it)->isBusy())
        {
            this->opipe_ << "#" << i  << " " << (*it)->getCookingPizza().getStrType() << " " <<  (*it)->getCookingPizza().getOrderNum()   << " ; ";
        }
        else
            this->opipe_ << "#" << i  <<  " Free ; ";
    }
    this->opipe_ << std::endl;
    ingr_stlist_t const &ingrs = this->kitchenstock_.getIngrList();
    ingr_stlist_t::const_iterator itt = ingrs.begin();
    this->opipe_ << "INGRS : ";
    for (;itt != ingrs.end(); ++itt)
    {
        this->opipe_ << itt->first << " : "  << itt->second << " ";
    }
    this->opipe_ << std::endl;
    this->opipe_ << "SUCCESS" << std::endl;

}

void        Kitchen::pizza(void)
{
    std::string     pizzacode;
    std::getline(this->ipipe_, pizzacode);
    Pizza &pizza = PizzaFactory::unpackPizza(pizzacode);
    this->acceptPizza(pizza);
    delete &pizza;
    this->opipe_ << "SUCCESS" << std::endl;
}

void        Kitchen::preparePipes(void)
{
    std::ostringstream       oss1;
    oss1 << "/tmp/pkin" << Kitchen::knum_;
    this->pipefilein_ = oss1.str();

    std::ostringstream      oss2;
    oss2 << "/tmp/pkout" << Kitchen::knum_;
    this->pipefileout_ = oss2.str();
    this->num_ = Kitchen::knum_;
    ++Kitchen::knum_;


    if (mkfifo(this->pipefileout_.c_str(), 0666) != 0)
        throw new Exception("Error : create a named pipe");
    if (mkfifo(this->pipefilein_.c_str(), 0666) != 0)
        throw new Exception("Error : create a named pipe");
}

bool    Kitchen::active(void)
{
    std::string         str;

    this->opipe_ << "ACTIVE" << std::endl;
    this->ipipe_ >> str;
    return (str == "ACTIVE");
}

void    Kitchen::run(void)
{
    std::string         cmd;

    try {
        while (this->ipipe_ >> cmd)
        {
            if (this->cmds_.find(cmd) != this->cmds_.end())
                (this->*cmds_[cmd])();
        }
    }
    catch (std::exception *e)
    {
        this->quit();
    }
}

std::string     &Kitchen::getReport(void)
{
    std::ostringstream      oss;
    std::string             str;

    this->opipe_ << "REPORT" << std::endl;
    while (std::getline(this->ipipe_, str))
    {
        oss << str << std::endl;
        if (str == "SUCCESS" || str == "ERROR")
        {
            return (* new std::string(oss.str()));
        }
    }
    return (* new std::string(oss.str()));
}

bool    Kitchen::acceptPizza(Pizza const &pizza)
{
    try
    {
        if (this->pid_ == 0)
        {
            if (this->kitchenpizzas_.size() > this->cookscount_)
                return (false);
            this->kitchenpizzas_.pushPizza(pizza);
            Cook::cookPizza();
        }
        else
        {
            std::string     &str = PizzaFactory::packPizza(pizza);
            this->opipe_ << "PIZZA " << str << std::endl;
            std::string     status;
            this->ipipe_ >> status;
            delete &str;
            if (status != "SUCCESS")
                return (false);
        }
    }
    catch (std::exception *e)
    {
        return (false);
    }
    return (true);
}

