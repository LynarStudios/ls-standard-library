/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-17
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowListValue.hpp>

ls::std::io::SerializableSectionPairRowListValue::SerializableSectionPairRowListValue(const ls::std::io::SerializableSectionPairParameter &_parameter) : ls::std::core::Class("SerializableSectionPairRowListValue")
{
  ::std::string message = this->getClassName() + ": model reference is null!";
  ls::std::core::NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

ls::std::io::SerializableSectionPairRowListValue::~SerializableSectionPairRowListValue() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairRowListValue::getValue()
{
  return this->parameter.getValue();
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRowListValue::marshal()
{
  ls::std::core::type::byte_field data{};

  for (const auto &_value : ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(this->getValue())->getList())
  {
    data += "  " + _value + this->parameter.getNewLine();
  }

  return data;
}

void ls::std::io::SerializableSectionPairRowListValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::EmptyStringArgumentEvaluator{_data}.evaluate();
  ls::std::core::type::byte_field searchText = _data;
  ::std::string newLine = this->parameter.getNewLine();

  while (!searchText.empty() && searchText != newLine)
  {
    ::std::string::size_type positionOfNewLine = searchText.find(newLine);
    ::std::string line = ls::std::io::SerializableSectionPairRowListValue::_getLine(positionOfNewLine, searchText);
    line = line.substr(2);
    ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(this->getValue())->add(line);
    this->_updateSearchText(positionOfNewLine, searchText);
  }
}

::std::string ls::std::io::SerializableSectionPairRowListValue::_getLine(::std::string::size_type _position, const ls::std::core::type::byte_field &_searchText)
{
  ::std::string line{};

  if (_position != ::std::string::npos)
  {
    line = _searchText.substr(0, _position);
  }
  else
  {
    line = _searchText;
  }

  return line;
}

void ls::std::io::SerializableSectionPairRowListValue::_updateSearchText(::std::string::size_type _position, ls::std::core::type::byte_field &_searchText)
{
  if (_position != ::std::string::npos)
  {
    _searchText = _searchText.substr(_position + this->parameter.getNewLine().size());
  }
  else
  {
    _searchText = "";
  }
}
