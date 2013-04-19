/*
** ResourceLock.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Wed Apr 17 21:42:26 2013 ivan ignatiev
** Last update Wed Apr 17 21:43:14 2013 ivan ignatiev
*/

#ifndef RESOURCELOCK_H_
# define RESOURCELOCK_H_

# include <pthread.h>

# include "Debug.hh"

class Mutex
{
    private:
        pthread_mutex_t     *mutex_;

        Mutex(Mutex const &mutex);
        Mutex &operator=(Mutex const &mutex);
    public:
        Mutex(void);

        void                lock(void);
        void                unlock(void);

        ~Mutex(void);
};

class MutexScopeLock
{
    private:
        Mutex &mutex_;

        MutexScopeLock(void);
        MutexScopeLock(MutexScopeLock const &);
        MutexScopeLock &operator=(MutexScopeLock const &);
    public:
        MutexScopeLock(Mutex &mutex);
        ~MutexScopeLock(void);
};

#endif /* !RESOURCELOCK_H_ */
