/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_CLASS_HPP
#define LS_STD_CLASS_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL Class // TODO: check if LS_STD_DYNAMIC_GOAL is set properly project wide
  {
    public:

      explicit Class(const ::std::string &_name);
      virtual ~Class();

      ::std::string getClassName();

    private:

      ::std::string name{};

      void _assignClassName(const ::std::string &_name);
  };
}

#endif
