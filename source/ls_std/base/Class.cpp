/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2021-04-24
 *
 * */

#include <ls_std/base/Class.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::Class::Class(const std::string &_name)
{
  this->_assignClassName(_name);
}

std::string ls_std::Class::getClassName()
{
  return this->name;
}

void ls_std::Class::_assignClassName(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->name = _name;
}
