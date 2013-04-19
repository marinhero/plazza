//
// ResourceLockTest.cpp for tests in /home/ignatiev/Projects/plazza/tests
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Thu Apr 18 19:04:58 2013 ivan ignatiev
// Last update Fri Apr 19 18:05:35 2013 ivan ignatiev
//

# include "ResourceLock.hh"
# include "tests/test.h"

int     main(void)
{
    Mutex mutex;
    MutexScopeLock locker(mutex);
    return (EXIT_SUCCESS);
}
