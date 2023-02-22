/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_ILLEGAL_OPERATION_EXCEPTION_HPP
#define LS_STD_ILLEGAL_OPERATION_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IllegalArithmeticOperationException : public ls::std::core::Exception
  {
    public:

      IllegalArithmeticOperationException();
      explicit IllegalArithmeticOperationException(::std::string _message);
      ~IllegalArithmeticOperationException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
