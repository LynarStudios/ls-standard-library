/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP
#define LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IncompleteJsonException : public ls::std::core::Exception
  {
    public:

      IncompleteJsonException();
      explicit IncompleteJsonException(::std::string _message);
      ~IncompleteJsonException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
