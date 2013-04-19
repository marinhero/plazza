//
// Debug.hh for plazza in /home/ignatiev/Projects/plazza
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Thu Apr 18 18:59:45 2013 ivan ignatiev
// Last update Thu Apr 18 19:12:15 2013 ivan ignatiev
//

#ifndef DEBUG_HH_
# define DEBUG_HH_

# ifdef DEBUG
#   include <iostream>
#   define TRACE(func, msg) std::clog << "[" #func "] " << (msg) << std::endl
# else
#   define TRACE(func, msg)
# endif

#endif
