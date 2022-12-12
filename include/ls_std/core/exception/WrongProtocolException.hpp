/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-12
 * Changed:         2022-12-12
 *
 * */

#ifndef LS_STD_WRONG_PROTOCOL_EXCEPTION_HPP
#define LS_STD_WRONG_PROTOCOL_EXCEPTION_HPP

#include <exception>

namespace ls::std::core
{
  class WrongProtocolException : public ::std::exception
  {
    public:

      explicit WrongProtocolException() = default;

      [[nodiscard]] const char *what() const noexcept override
      {
        return "WrongProtocolException thrown - the available protocol is not valid for this operation!";
      }
  };
}

#endif
