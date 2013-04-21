//
// Talk.hh for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sun Apr 21 16:33:51 2013 Marin Alcaraz
// Last update Sun Apr 21 19:56:44 2013 Marin Alcaraz
//

#ifndef TALK_H
# define TALK_H

#include    <sys/types.h>
#include    <sys/stat.h>
#include    <iostream>
#include    <fstream>
#include    "Exception.hh"
#include    <fcntl.h>
class Talk
{
    private:
        std::string                 name;
        std::ifstream               ifile;
        std::ofstream               ofile;

    public:
        Talk(std::string);
        ~Talk();
        std::ofstream             &out();
        std::ifstream             &in();
};

#endif /* TALK */
