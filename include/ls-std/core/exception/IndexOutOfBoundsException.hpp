/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_INDEX_OUT_OF_BOUNDS_EXCEPTION_HPP
#define LS_STD_INDEX_OUT_OF_BOUNDS_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IndexOutOfBoundsException : public ls::std::core::Exception
  {
    public:

      IndexOutOfBoundsException();
      explicit IndexOutOfBoundsException(::std::string _message);
      ~IndexOutOfBoundsException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
