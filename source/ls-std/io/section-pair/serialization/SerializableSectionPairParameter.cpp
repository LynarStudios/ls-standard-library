/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-23
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairParameter.hpp>

using ls::std::core::Class;
using ls::std::io::NewLine;
using ls::std::io::SerializableSectionPairParameter;
using std::shared_ptr;
using std::string;

SerializableSectionPairParameter::SerializableSectionPairParameter() : parseNewLine(NewLine::get())
{}

SerializableSectionPairParameter::~SerializableSectionPairParameter() = default;

string SerializableSectionPairParameter::getNewLine()
{
  return this->parseNewLine;
}

shared_ptr<Class> SerializableSectionPairParameter::getValue() const
{
  return this->value;
}

void SerializableSectionPairParameter::setNewLine(const string &_newLine)
{
  this->parseNewLine = _newLine;
}

void SerializableSectionPairParameter::setValue(const shared_ptr<Class> &_value)
{
  this->value = _value;
}
