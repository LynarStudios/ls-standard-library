/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP
#define LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP

#include <exception>

namespace ls::std::core
{
  class IncompleteJsonException : public ::std::exception
  {
    public:

      explicit IncompleteJsonException() = default;

      [[nodiscard]] const char *what() const noexcept override
      {
        return "IncompleteJsonException thrown - this JSON string is incomplete.";
      }
  };
}

#endif
