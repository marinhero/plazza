//
// ResourceLock.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Wed Apr 17 21:42:02 2013 ivan ignatiev
// Last update Fri Apr 19 20:23:34 2013 ivan ignatiev
//

#include "ResourceLock.hh"

Mutex::Mutex(void)
{
    TRACE(Mutex::Mutex, "Mutex init");
    this->mutex_ = new pthread_mutex_t;
    pthread_mutex_init(this->mutex_, NULL);
}

Mutex::~Mutex(void)
{
    TRACE(Mutex::~Mutex, "Mutex destroyed");
    pthread_mutex_destroy(this->mutex_);
    delete this->mutex_;
}

Mutex::Mutex(Mutex const &)
{
}

Mutex &Mutex::operator=(Mutex const &)
{
    return (*this);
}

void Mutex::lock(void)
{
    TRACE(Mutex::lock, "Mutex lock");
    pthread_mutex_lock(this->mutex_);
}

void Mutex::unlock(void)
{
    TRACE(Mutex::unlock, "Mutex unlock");
    pthread_mutex_unlock(this->mutex_);
}

MutexScopeLock::MutexScopeLock(void)
    : mutex_(* new Mutex())
{
}

MutexScopeLock::MutexScopeLock(MutexScopeLock const &)
    : mutex_(* new Mutex())
{
}

MutexScopeLock &MutexScopeLock::operator=(MutexScopeLock const &)
{
    return (*this);
}

MutexScopeLock::MutexScopeLock(Mutex &mutex)
: mutex_(mutex)
{
    TRACE(MutexScopeLock::MutexScopeLock, "Mutex lock");
    mutex.lock();
}

MutexScopeLock::~MutexScopeLock(void)
{
    TRACE(MutexScopeLock::~MutexScopeLock, "Mutex unlock");
    this->mutex_.unlock();
}
