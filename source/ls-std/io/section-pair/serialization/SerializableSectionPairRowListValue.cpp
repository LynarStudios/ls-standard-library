/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-24
*
* */

#include <list>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowListValue.hpp>
#include <numeric>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRowListValue;
using std::accumulate;
using std::dynamic_pointer_cast;
using std::list;
using std::move;
using std::shared_ptr;
using std::string;

SerializableSectionPairRowListValue::SerializableSectionPairRowListValue(const SerializableSectionPairParameter &_parameter) : Class("SerializableSectionPairRowListValue")
{
  string message = this->getClassName() + ": model reference is null!";
  NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

SerializableSectionPairRowListValue::~SerializableSectionPairRowListValue() noexcept = default;

shared_ptr<Class> SerializableSectionPairRowListValue::getValue()
{
  return this->parameter.getValue();
}

byte_field SerializableSectionPairRowListValue::marshal()
{
  list<section_pair_row_value> listValue = dynamic_pointer_cast<SectionPairRowListValue>(this->getValue())->getList();
  return accumulate(listValue.begin(), listValue.end(), byte_field{}, [this](byte_field data, const byte_field &_value) { return ::move(data) + "  " + _value + this->parameter.getNewLine(); });
}

void SerializableSectionPairRowListValue::unmarshal(const byte_field &_data)
{
  EmptyStringArgumentEvaluator{_data}.evaluate();
  byte_field searchText = _data;
  string newLine = this->parameter.getNewLine();

  while (!searchText.empty() && searchText != newLine)
  {
    string::size_type positionOfNewLine = searchText.find(newLine);
    string line = SerializableSectionPairRowListValue::_getLine(positionOfNewLine, searchText);
    line = line.substr(2);
    dynamic_pointer_cast<SectionPairRowListValue>(this->getValue())->add(line);
    this->_updateSearchText(positionOfNewLine, searchText);
  }
}

string SerializableSectionPairRowListValue::_getLine(string::size_type _position, const byte_field &_searchText)
{
  string line{};

  if (_position != string::npos)
  {
    line = _searchText.substr(0, _position);
  }
  else
  {
    line = _searchText;
  }

  return line;
}

void SerializableSectionPairRowListValue::_updateSearchText(string::size_type _position, byte_field &_searchText)
{
  if (_position != string::npos)
  {
    _searchText = _searchText.substr(_position + this->parameter.getNewLine().size());
  }
  else
  {
    _searchText = "";
  }
}
