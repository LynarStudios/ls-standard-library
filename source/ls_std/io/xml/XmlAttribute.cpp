/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2021-07-16
 *
 * */

#include <ls_std/io/xml/XmlAttribute.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::XmlAttribute::XmlAttribute(const std::string& _name) : ls_std::Class("XmlAttribute")
{
  this->_assignName(_name);
}

std::string ls_std::XmlAttribute::getName()
{
  return this->name;
}

std::string ls_std::XmlAttribute::getValue()
{
  return this->value;
}

void ls_std::XmlAttribute::setName(const std::string& _name)
{
  this->_assignName(_name);
}

void ls_std::XmlAttribute::setValue(const std::string& _value)
{
  this->_assignValue(_value);
}

std::string ls_std::XmlAttribute::toXml()
{
  return this->name + "=\"" + this->value + "\"";
}

void ls_std::XmlAttribute::_assignName(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->name = _name;
}

void ls_std::XmlAttribute::_assignValue(const std::string &_value)
{
  if (_value.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}
