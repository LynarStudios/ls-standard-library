/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2022-06-29
 *
 * */

#ifndef LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP
#define LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP

#include <exception>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class DYNAMIC_GOAL IllegalArgumentException : public ::std::exception
      {
        public:

          IllegalArgumentException() = default;

          const char *what() const noexcept override
          {
            return "IllegalArgumentException thrown - passed argument is not valid!";
          }
      };
    }
  }
}

#endif
