/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_LIBRARY_VERSION_HPP
#define LS_STD_LIBRARY_VERSION_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL LibraryVersion
  {
    public:

      LibraryVersion();
      ~LibraryVersion();

      static ::std::string getVersion();
  };
}

#endif
