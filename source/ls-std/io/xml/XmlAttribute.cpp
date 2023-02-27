/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlAttribute.hpp>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::io::XmlAttribute;
using std::string;

XmlAttribute::XmlAttribute(const string &_name) : Class("XmlAttribute")
{
  this->_assignName(_name);
}

XmlAttribute::~XmlAttribute() noexcept = default;

string XmlAttribute::getName()
{
  return this->name;
}

string XmlAttribute::getValue()
{
  return this->value;
}

void XmlAttribute::setName(const string &_name)
{
  this->_assignName(_name);
}

void XmlAttribute::setValue(const string &_value)
{
  this->_assignValue(_value);
}

string XmlAttribute::toXml()
{
  return this->name + "=\"" + this->value + "\"";
}

void XmlAttribute::_assignName(const string &_name)
{
  EmptyStringArgumentEvaluator{_name, "xml attribute name is empty!"}.evaluate();
  this->name = _name;
}

void XmlAttribute::_assignValue(const string &_value)
{
  EmptyStringArgumentEvaluator{_value, "xml attribute value is empty!"}.evaluate();
  this->value = _value;
}
