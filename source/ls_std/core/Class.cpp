/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-12-23
 *
 * */

#include <ls_std/core/Class.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::core::Class::Class(const ::std::string &_name)
{
  this->_assignClassName(_name);
}

ls::std::core::Class::~Class()
= default;

::std::string ls::std::core::Class::getClassName()
{
  return this->name;
}

void ls::std::core::Class::_assignClassName(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->name = _name;
}
