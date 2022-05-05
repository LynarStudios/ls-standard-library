/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/core/Class.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

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
