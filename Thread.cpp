//
// Thread.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Wed Apr 17 21:09:46 2013 ivan ignatiev
// Last update Sun Apr 21 19:39:19 2013 ivan ignatiev
//

#include "Thread.hh"

Thread &Thread::operator=(Thread const &)
{
    return (*this);
}

Thread::Thread(IThreaded &threadobj)
    : threadobj_(threadobj)
{
    if (pthread_create(&this->thread_, NULL, Thread::proccess, reinterpret_cast<void*>(this)) != 0)
        throw new std::exception();
}

Thread::~Thread(void)
{
    pthread_join(this->thread_, NULL);
}

void    *Thread::run(void)
{
    return (this->threadobj_.run());
}

void    *Thread::proccess(void *obj)
{
    Thread  *th = reinterpret_cast<Thread *>(obj);
    return (th->run());
}

IThreaded::~IThreaded(void)
{

}


