/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/Class.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>

ls::std::core::Class::Class(const ::std::string &_name)
{
  this->_assignClassName(_name);
}

ls::std::core::Class::~Class() = default;

::std::string ls::std::core::Class::getClassName()
{
  return this->name;
}

void ls::std::core::Class::_assignClassName(const ::std::string &_name)
{
  ls::std::core::EmptyStringArgumentEvaluator{_name, "class name is empty!"}.evaluate();
  this->name = _name;
}
