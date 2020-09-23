/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2020-09-23
 *
 * */

#include "XMLAttribute.hpp"

ls_std::XMLAttribute::XMLAttribute() : Class("XMLAttribute")
{}

std::string ls_std::XMLAttribute::getName()
{
  return this->name;
}

std::string ls_std::XMLAttribute::getValue()
{
  return this->value;
}

void ls_std::XMLAttribute::setName(std::string _name)
{
  this->name = std::move(_name);
}

void ls_std::XMLAttribute::setValue(std::string _value)
{
  this->value = std::move(_value);
}

std::string ls_std::XMLAttribute::toXML()
{
  return this->name + "=\"" + this->value + "\"";
}
