/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP
#define LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP

#include <ls-std/core/exception/Exception.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL FileNotFoundException : public ls::std::core::Exception
  {
    public:

      FileNotFoundException();
      explicit FileNotFoundException(::std::string _message);
      ~FileNotFoundException() noexcept override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
