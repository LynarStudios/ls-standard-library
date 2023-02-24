/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/Class.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using std::string;

Class::Class(const string &_name)
{
  this->_assignClassName(_name);
}

Class::~Class() = default;

string Class::getClassName()
{
  return this->name;
}

void Class::_assignClassName(const string &_name)
{
  EmptyStringArgumentEvaluator{_name, "class name is empty!"}.evaluate();
  this->name = _name;
}
