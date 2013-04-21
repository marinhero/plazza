/*
** Thread.h for plazza in /home/ignatiev/Projects/plazza
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Wed Apr 17 21:10:01 2013 ivan ignatiev
** Last update Wed Apr 17 21:11:19 2013 ivan ignatiev
*/

#ifndef THREAD_H_
# define THREAD_H_

# include <unistd.h>
# include <pthread.h>

# include "Exception.hh"

class IThreaded
{
    public:
        virtual void *run(void) = 0;
        virtual ~IThreaded();
};

class Thread
{
    private:
        pthread_t   thread_;
        IThreaded   &threadobj_;

        Thread &operator=(Thread const &);
    public:
        Thread(IThreaded &thread);
        void        *run(void);
        static void *proccess(void *);

        ~Thread(void);
};

#endif /* !THREAD_H_ */
