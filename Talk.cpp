//
// Talk.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sun Apr 21 16:52:35 2013 Marin Alcaraz
// Last update Sun Apr 21 20:02:19 2013 Marin Alcaraz
//

#include "Talk.hh"


Talk::Talk(std::string n) : name(n)
{
    mkfifo(this->name.c_str(),0666);
    std::cout << "Created file " << this->name << std::endl;
    try
    {
        ofile.open(n.c_str(), std::ofstream::out);
        ifile.open(n.c_str(), std::ifstream::in);
    }
    catch (std::exception *e)
    {
        std::cerr << e->what() << std::endl;
    }
}

Talk::~Talk()
{
    ifile.close();
    ofile.close();
}

std::ifstream    &Talk::in()
{
    return (this->ifile);
}

std::ofstream    &Talk::out()
{
    return (this->ofile);
}
