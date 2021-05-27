/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/xml/XmlAttribute.hpp>

ls_std::XmlAttribute::XmlAttribute(std::string _name)
    : ls_std::Class("XmlAttribute"),
      name(std::move(_name))
{}

std::string ls_std::XmlAttribute::getName()
{
  return this->name;
}

std::string ls_std::XmlAttribute::getValue()
{
  return this->value;
}

void ls_std::XmlAttribute::setName(std::string _name)
{
  this->name = std::move(_name);
}

void ls_std::XmlAttribute::setValue(std::string _value)
{
  this->value = std::move(_value);
}

std::string ls_std::XmlAttribute::toXml()
{
  return this->name + "=\"" + this->value + "\"";
}
