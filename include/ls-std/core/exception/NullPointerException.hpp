/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_NULL_POINTER_EXCEPTION_HPP
#define LS_STD_NULL_POINTER_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL NullPointerException : public ls::std::core::Exception
  {
    public:

      NullPointerException();
      explicit NullPointerException(::std::string _message);
      ~NullPointerException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
