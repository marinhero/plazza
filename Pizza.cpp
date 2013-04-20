//
// Pizza.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:07:45 2013 ivan ignatiev
// Last update Sat Apr 20 17:38:53 2013 ivan ignatiev
//

#include "Pizza.hh"

std::map<Pizza::TaillePizza, std::string> Pizza::sizes_;

Pizza::Pizza(void)
{
}

Pizza::~Pizza(void)
{
    TRACE(Pizza::~Pizza, "Pizza destroy");
}

Pizza::Pizza(Pizza::TypePizza type, Pizza::TaillePizza size)
    : type_(type), size_(size)
{
    TRACE(Pizza::Pizza, "Pizza create");
    this->init();
}

Pizza::Pizza(Pizza const &pizza)
    : type_(pizza.getType()), size_(pizza.getSize())
{
    TRACE(Pizza::Pizza, "Pizza create by copy constructor");
    this->init();
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

void Pizza::init(void)
{
    if (Pizza::sizes_.size() == 0)
    {
        Pizza::sizes_[Pizza::S] = "S";
        Pizza::sizes_[Pizza::M] = "M";
        Pizza::sizes_[Pizza::L] = "L";
        Pizza::sizes_[Pizza::XL] = "XL";
        Pizza::sizes_[Pizza::XXL] = "XXL";
    }
}

Pizza::TypePizza Pizza::getType(void) const
{
    return (this->type_);
}

Pizza::TaillePizza Pizza::getSize(void) const
{
    return (this->size_);
}

int Pizza::getCookTime(void) const
{
    return (this->cooktime_);
}

std::string const &Pizza::getStrSize(void) const
{
    return (Pizza::sizes_[this->size_]);
}

void Pizza::setCookTime(int cooktime)
{
    this->cooktime_ = cooktime;
}

void Pizza::setType(Pizza::TypePizza type)
{
    this->type_ = type;
}

void Pizza::setSize(Pizza::TaillePizza size)
{
    this->size_ = size;
}


/* Margarita */

Margarita::Margarita(void)
    : Pizza(Pizza::Margarita, Pizza::S)
{
}

Margarita::Margarita(Pizza::TaillePizza size)
    : Pizza(Pizza::Margarita, size) , strtype_("margarita")
{
    this->initIngr();
}

Margarita::Margarita(Margarita const &pizza)
    : Pizza(pizza) , strtype_("margarita")
{
    this->initIngr();
}

Margarita::~Margarita(void)
{

}

void Margarita::initIngr(void)
{
    this->ingrs_["doe"] = 1;
    this->ingrs_["tomato"] = 1;
    this->ingrs_["gruyere"] = 1;
    this->setCookTime(1);
}

std::string const &Margarita::getStrType(void) const
{
    return (this->strtype_);
}

ingr_stlist_t const &Margarita::getIngr(void) const
{
    return (this->ingrs_);
}

Pizza & Margarita::clone(Pizza::TaillePizza size) const
{
    TRACE(Margarita::clone, "Make new Margarita");
    return (* new Margarita(size));
}

/* Regina */

Regina::Regina(void)
    : Pizza(Pizza::Regina, Pizza::S)
{
}

Regina::Regina(Pizza::TaillePizza size)
    : Pizza(Pizza::Regina, size) , strtype_("regina")
{
    this->initIngr();
}

Regina::Regina(Regina const &pizza)
    : Pizza(pizza) , strtype_("regina")
{
    this->initIngr();
}

Regina::~Regina(void)
{

}

void Regina::initIngr(void)
{
    this->ingrs_["doe"] = 1;
    this->ingrs_["tomato"] = 1;
    this->ingrs_["gruyere"] = 1;
    this->ingrs_["ham"] = 1;
    this->ingrs_["mushrooms"] = 1;
    this->setCookTime(2);
}

std::string const &Regina::getStrType(void) const
{
    return (this->strtype_);
}

ingr_stlist_t const &Regina::getIngr(void) const
{
    return (this->ingrs_);
}

Pizza & Regina::clone(Pizza::TaillePizza size) const
{
    TRACE(Regina::clone, "Make new Regina");
    return (* new Regina(size));
}

/* Americana */

Americana::Americana(void)
    : Pizza(Pizza::Americaine, Pizza::S)
{
}

Americana::Americana(Pizza::TaillePizza size)
    : Pizza(Pizza::Americaine, size) , strtype_("americana")
{
    this->initIngr();
}

Americana::Americana(Americana const &pizza)
    : Pizza(pizza) , strtype_("americana")
{
    this->initIngr();
}

Americana::~Americana(void)
{

}

void Americana::initIngr(void)
{
    this->ingrs_["doe"] = 1;
    this->ingrs_["tomato"] = 1;
    this->ingrs_["gruyere"] = 1;
    this->ingrs_["steak"] = 1;
    this->setCookTime(2);
}

std::string const &Americana::getStrType(void) const
{
    TRACE(Americana::getStrType, std::string("get type : ") + strtype_);
    return (this->strtype_);
}

ingr_stlist_t const &Americana::getIngr(void) const
{
    return (this->ingrs_);
}

Pizza & Americana::clone(Pizza::TaillePizza size) const
{
    TRACE(Americana::clone, "Make new Americana");
    return (* new Americana(size));
}

/* Fantasia */

Fantasia::Fantasia(void)
    : Pizza(Pizza::Fantasia, Pizza::S)
{
}

Fantasia::Fantasia(Pizza::TaillePizza size)
    : Pizza(Pizza::Fantasia, size) , strtype_("fantasia")
{
    this->initIngr();
}

Fantasia::Fantasia(Fantasia const &pizza)
    : Pizza(pizza) , strtype_("fantasia")
{
    this->initIngr();
}

Fantasia::~Fantasia(void)
{

}

void Fantasia::initIngr(void)
{
    this->ingrs_["doe"] = 1;
    this->ingrs_["tomato"] = 1;
    this->ingrs_["goat cheese"] = 1;
    this->ingrs_["eggplant"] = 1;
    this->ingrs_["chief love"] = 1;
    this->setCookTime(4);
}

std::string const &Fantasia::getStrType(void) const
{
    return (this->strtype_);
}

ingr_stlist_t const &Fantasia::getIngr(void) const
{
    return (this->ingrs_);
}

Pizza & Fantasia::clone(Pizza::TaillePizza size) const
{
    TRACE(Fantasia::clone, "Make new Fantasia");
    return (* new Fantasia(size));
}

