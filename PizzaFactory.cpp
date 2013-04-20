//
// PizzaFactory.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Apr 20 15:04:46 2013 ivan ignatiev
// Last update Sun Apr 21 00:17:32 2013 ivan ignatiev
//

# include "PizzaFactory.hh"

int                                         PizzaFactory::factory_count_ = 0;
std::map<std::string, Pizza *>               PizzaFactory::pizzas_;
std::map<std::string, Pizza::TaillePizza>   PizzaFactory::sizes_;
ingr_stlist_t                               PizzaFactory::ingrs_;

static  PizzaFactory    pizza_factory;

PizzaFactory::PizzaFactory(void)
{
    if (factory_count_ > 0)
        throw new std::exception();
    ++factory_count_;
    PizzaFactory::learn();
}

PizzaFactory::PizzaFactory(PizzaFactory const &)
{

}

PizzaFactory &PizzaFactory::operator=(PizzaFactory const &)
{
    return (*this);
}

PizzaFactory::~PizzaFactory(void)
{
    PizzaFactory::forget();
}

void PizzaFactory::learn(void)
{
    PizzaFactory::learnPizza(* new Margarita(Pizza::S));
    PizzaFactory::learnPizza(* new Regina(Pizza::S));
    PizzaFactory::learnPizza(* new Americana(Pizza::S));
    PizzaFactory::learnPizza(* new Fantasia(Pizza::S));

    PizzaFactory::learnSize("S", Pizza::S);
    PizzaFactory::learnSize("M", Pizza::M);
    PizzaFactory::learnSize("L", Pizza::L);
    PizzaFactory::learnSize("XL", Pizza::XL);
    PizzaFactory::learnSize("XXL", Pizza::XXL);
}

void PizzaFactory::forget(void)
{
    std::map<std::string, Pizza *>::iterator    it = PizzaFactory::pizzas_.begin();
    for (;it != PizzaFactory::pizzas_.end(); ++it)
       delete it->second;
}

void PizzaFactory::learnPizza(Pizza &pizza)
{
    if (PizzaFactory::pizzas_.find(pizza.getStrType()) == PizzaFactory::pizzas_.end())
    {
        PizzaFactory::pizzas_[pizza.getStrType()] = &pizza;
        ingr_stlist_t const &ingrs  = pizza.getIngr();
        ingr_stlist_t::const_iterator it = ingrs.begin();
        for (;it != ingrs.end(); ++it)
            PizzaFactory::ingrs_[it->first] = 1;
    }
}

void PizzaFactory::learnSize(std::string const &size, Pizza::TaillePizza realsize)
{
    if (PizzaFactory::sizes_.find(size) == PizzaFactory::sizes_.end())
        PizzaFactory::sizes_[size] = realsize;
}

Pizza &PizzaFactory::createPizza(std::string const &type, std::string const &size, int ordernum)
{
    if (PizzaFactory::pizzas_.find(type) == PizzaFactory::pizzas_.end())
        throw new std::exception();
    if (PizzaFactory::sizes_.find(size) == PizzaFactory::sizes_.end())
        throw new std::exception();
    Pizza &pizza = PizzaFactory::pizzas_[type]->clone();
    pizza.setSize(PizzaFactory::sizes_[size]);
    pizza.setOrderNum(ordernum);
    return (pizza);
}

ingr_stlist_t   const   &PizzaFactory::ingrList(void)
{
    return (PizzaFactory::ingrs_);
}

