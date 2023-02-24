/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/Exception.hpp>

using ls::std::core::Exception;
using std::move;
using std::string;

Exception::Exception(string _name) : name(::move(_name))
{}

Exception::~Exception() noexcept = default;

string Exception::getName() const
{
  return this->name;
}

const char *Exception::what() const noexcept
{
  return "base exception class in use - method not implemented!";
}
