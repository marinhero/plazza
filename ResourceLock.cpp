//
// ResourceLock.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Wed Apr 17 21:42:02 2013 ivan ignatiev
// Last update Sun Apr 21 18:47:53 2013 ivan ignatiev
//

#include "ResourceLock.hh"

Mutex::Mutex(void)
{
    TRACE(Mutex::Mutex, "Mutex init");
    pthread_mutex_init(&this->mutex_, NULL);
}

Mutex::~Mutex(void)
{
    TRACE(Mutex::~Mutex, "Mutex destroyed");
    pthread_mutex_destroy(&this->mutex_);
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
    pthread_mutex_lock(&this->mutex_);
}

void Mutex::unlock(void)
{
    TRACE(Mutex::unlock, "Mutex unlock");
    pthread_mutex_unlock(&this->mutex_);
}

CondVariable::CondVariable(void)
{
    pthread_cond_init(&this->cond_, NULL);
    pthread_mutex_init(&this->mutex_, NULL);
}

CondVariable::~CondVariable(void)
{
    pthread_cond_destroy(&this->cond_);
    pthread_mutex_destroy(&this->mutex_);
}

void    CondVariable::freeaze(void)
{
    pthread_mutex_lock(&this->mutex_);
    pthread_cond_wait(&this->cond_, &this->mutex_);
    pthread_mutex_unlock(&this->mutex_);
}

void    CondVariable::unfreaze_one(void)
{
    pthread_cond_signal(&this->cond_);
}

void    CondVariable::unfreeze_all(void)
{
    pthread_cond_broadcast(&this->cond_);
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
