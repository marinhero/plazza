//
// Pizza.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Tue Apr 16 15:07:45 2013 ivan ignatiev
// Last update Sun Apr 21 21:23:03 2013 ivan ignatiev
//

#include "Pizza.hh"

Pizza::Pizza(void)
{
}

Pizza::~Pizza(void)
{
    TRACE(Pizza::~Pizza, "Pizza destroy");
}

Pizza::Pizza(Pizza::TypePizza type, Pizza::TaillePizza size, int ordernum = 0)
    : type_(type), size_(size), ordernum_(ordernum)
{
    TRACE(Pizza::Pizza, "Pizza create");
    this->init();
}

Pizza::Pizza(Pizza const &pizza)
    : type_(pizza.getType()), size_(pizza.getSize()), ordernum_(pizza.getOrderNum())
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
        this->ordernum_ = pizza.getOrderNum();
    }
    return (*this);
}

void Pizza::init(void)
{
    this->sizes_[Pizza::S] = "S";
    this->sizes_[Pizza::M] = "M";
    this->sizes_[Pizza::L] = "L";
    this->sizes_[Pizza::XL] = "XL";
    this->sizes_[Pizza::XXL] = "XXL";
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

int Pizza::getOrderNum(void) const
{
    return (this->ordernum_);
}

std::string const &Pizza::getStrSize(void) const
{
    if (this->sizes_.find(this->size_) != this->sizes_.end())
        return ( (this->sizes_.find(this->size_))->second );
    throw new std::exception();
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

void Pizza::setOrderNum(int ordernum)
{
    this->ordernum_ = ordernum;
}

/* Margarita */

Margarita::Margarita(void)
    : Pizza(Pizza::Margarita, Pizza::S)
{
}

Margarita::Margarita(Pizza::TaillePizza size, int ordernum)
    : Pizza(Pizza::Margarita, size, ordernum) , strtype_("margarita")
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

Pizza & Margarita::clone(void) const
{
    TRACE(Margarita::clone, "Make new Margarita");
    return (* new Margarita(this->getSize(), this->getOrderNum()));
}

/* Regina */

Regina::Regina(void)
    : Pizza(Pizza::Regina, Pizza::S)
{
}

Regina::Regina(Pizza::TaillePizza size, int ordernum)
    : Pizza(Pizza::Regina, size, ordernum) , strtype_("regina")
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

Pizza & Regina::clone(void) const
{
    TRACE(Regina::clone, "Make new Regina");
    return (* new Regina(this->getSize(), this->getOrderNum()));
}

/* Americana */

Americana::Americana(void)
    : Pizza(Pizza::Americaine, Pizza::S)
{
}

Americana::Americana(Pizza::TaillePizza size, int ordernum)
    : Pizza(Pizza::Americaine, size, ordernum) , strtype_("americana")
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

Pizza & Americana::clone(void) const
{
    TRACE(Americana::clone, "Make new Americana");
    return (* new Americana(this->getSize(), this->getOrderNum()));
}

/* Fantasia */

Fantasia::Fantasia(void)
    : Pizza(Pizza::Fantasia, Pizza::S)
{
}

Fantasia::Fantasia(Pizza::TaillePizza size, int ordernum)
    : Pizza(Pizza::Fantasia, size, ordernum) , strtype_("fantasia")
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

Pizza & Fantasia::clone(void) const
{
    TRACE(Fantasia::clone, "Make new Fantasia");
    return (* new Fantasia(this->getSize(), this->getOrderNum()));
}
