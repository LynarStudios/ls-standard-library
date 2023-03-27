/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-27
* Changed:         2023-03-27
*
* */

#ifndef LS_STD_NOT_IMPLEMENTED_EXCEPTION_HPP
#define LS_STD_NOT_IMPLEMENTED_EXCEPTION_HPP

#include "Exception.hpp"
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL NotImplementedException : public ls::std::core::Exception
  {
    public:

      NotImplementedException();
      explicit NotImplementedException(::std::string _message);
      ~NotImplementedException() noexcept override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
