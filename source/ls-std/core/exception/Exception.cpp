/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-22
*
* */

#include <ls-std/core/exception/Exception.hpp>

ls::std::core::Exception::Exception(::std::string _name) : name(::std::move(_name))
{}

ls::std::core::Exception::~Exception() = default;

::std::string ls::std::core::Exception::getName()
{
  return this->name;
}

const char *ls::std::core::Exception::what() const noexcept
{
  return "base exception class class in use - method not implemented!";
}
