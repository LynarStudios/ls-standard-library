/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_FILE_OPERATION_EXCEPTION_HPP
#define LS_STD_FILE_OPERATION_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL FileOperationException : public ls::std::core::Exception
  {
    public:

      FileOperationException();
      explicit FileOperationException(::std::string _message);
      ~FileOperationException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
