/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2023-02-03
 *
 * */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/xml/XmlAttribute.hpp>

ls::std::io::XmlAttribute::XmlAttribute(const ::std::string& _name) : ls::std::core::Class("XmlAttribute")
{
  this->_assignName(_name);
}

::std::string ls::std::io::XmlAttribute::getName()
{
  return this->name;
}

::std::string ls::std::io::XmlAttribute::getValue()
{
  return this->value;
}

void ls::std::io::XmlAttribute::setName(const ::std::string& _name)
{
  this->_assignName(_name);
}

void ls::std::io::XmlAttribute::setValue(const ::std::string& _value)
{
  this->_assignValue(_value);
}

::std::string ls::std::io::XmlAttribute::toXml()
{
  return this->name + "=\"" + this->value + "\"";
}

void ls::std::io::XmlAttribute::_assignName(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->name = _name;
}

void ls::std::io::XmlAttribute::_assignValue(const ::std::string &_value)
{
  if (_value.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}
