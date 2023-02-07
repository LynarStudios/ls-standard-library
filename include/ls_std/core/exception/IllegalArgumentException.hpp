/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP
#define LS_STD_ILLEGAL_ARGUMENT_EXCEPTION_HPP

#include <exception>

namespace ls::std::core
{
  class IllegalArgumentException : public ::std::exception
  {
    public:

      IllegalArgumentException() = default;
      //ToDo: possibility to pass argument name

      [[nodiscard]] const char *what() const noexcept override
      {
        return "IllegalArgumentException thrown - passed argument is not valid!";
      }
  };
}

#endif
