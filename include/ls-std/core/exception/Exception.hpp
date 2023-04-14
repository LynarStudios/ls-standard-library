/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-03-28
*
* */

#ifndef LS_STD_EXCEPTION_HPP
#define LS_STD_EXCEPTION_HPP

#include <exception>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL Exception : public ::std::exception
  {
    public:

      explicit Exception(::std::string _name);
      ~Exception() noexcept override;

      [[nodiscard]] ::std::string getName() const;
      [[nodiscard]] const char *what() const noexcept override = 0;

    protected:

      ::std::string message{};
      ::std::string name{};

      [[nodiscard]] const char *_getIdentifiedMessage(const ::std::string &_defaultMessage) const;
  };
}

#endif
