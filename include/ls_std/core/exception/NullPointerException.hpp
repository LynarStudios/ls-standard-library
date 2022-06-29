/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2022-06-29
 *
 * */

#ifndef LS_STD_NULL_POINTER_EXCEPTION_HPP
#define LS_STD_NULL_POINTER_EXCEPTION_HPP

#include <exception>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class DYNAMIC_GOAL NullPointerException : public ::std::exception
      {
        public:

          explicit NullPointerException() = default;

          const char *what() const noexcept override
          {
            return "NullPointerException thrown - reference is null!";
          }
      };
    }
  }
}

#endif
