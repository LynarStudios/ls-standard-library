/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-10-29
 *
 * */

#include "Class.hpp"

ls_std::Class::Class(std::string _name):
name(std::move(_name))
{}

std::string ls_std::Class::getClassName()
{
  return this->name;
}
