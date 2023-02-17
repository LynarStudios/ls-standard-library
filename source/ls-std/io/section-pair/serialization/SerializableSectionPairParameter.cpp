/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-17
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairParameter.hpp>

ls::std::io::SerializableSectionPairParameter::SerializableSectionPairParameter() : parseNewLine(ls::std::io::NewLine::get())
{}

ls::std::io::SerializableSectionPairParameter::~SerializableSectionPairParameter() = default;

::std::string ls::std::io::SerializableSectionPairParameter::getNewLine()
{
  return this->parseNewLine;
}

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairParameter::getValue() const
{
  return this->value;
}

void ls::std::io::SerializableSectionPairParameter::setNewLine(const ::std::string &_newLine)
{
  this->parseNewLine = _newLine;
}

void ls::std::io::SerializableSectionPairParameter::setValue(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  this->value = _value;
}
