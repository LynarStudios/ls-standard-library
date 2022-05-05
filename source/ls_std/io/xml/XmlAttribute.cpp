/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/xml/XmlAttribute.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::XmlAttribute::XmlAttribute(const std::string& _name) : ls::Class("XmlAttribute")
{
  this->_assignName(_name);
}

std::string ls::XmlAttribute::getName()
{
  return this->name;
}

std::string ls::XmlAttribute::getValue()
{
  return this->value;
}

void ls::XmlAttribute::setName(const std::string& _name)
{
  this->_assignName(_name);
}

void ls::XmlAttribute::setValue(const std::string& _value)
{
  this->_assignValue(_value);
}

std::string ls::XmlAttribute::toXml()
{
  return this->name + "=\"" + this->value + "\"";
}

void ls::XmlAttribute::_assignName(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->name = _name;
}

void ls::XmlAttribute::_assignValue(const std::string &_value)
{
  if (_value.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->value = _value;
}
