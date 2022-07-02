/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_NULL_POINTER_EXCEPTION_HPP
#define LS_STD_NULL_POINTER_EXCEPTION_HPP

#include <exception>

namespace ls::std::core
{
  class NullPointerException : public ::std::exception
  {
    public:

      explicit NullPointerException() = default;

      const char *what() const noexcept override
      {
        return "NullPointerException thrown - reference is null!";
      }
  };
}

#endif
