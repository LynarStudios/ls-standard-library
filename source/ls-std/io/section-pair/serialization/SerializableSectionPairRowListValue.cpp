/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-11
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowListValue.hpp>

ls::std::io::SerializableSectionPairRowListValue::SerializableSectionPairRowListValue(const ::std::shared_ptr<ls::std::io::SectionPairRowListValue> &_value)
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairRowListValue::~SerializableSectionPairRowListValue() = default;

::std::shared_ptr<ls::std::io::SectionPairRowListValue> ls::std::io::SerializableSectionPairRowListValue::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRowListValue::marshal()
{
  ls::std::core::type::byte_field data{};

  for (const auto &_value : this->value->getList())
  {
    data += "  " + _value + ls::std::io::NewLine::get();
  }

  return data;
}

void ls::std::io::SerializableSectionPairRowListValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::EmptyStringArgumentEvaluator{_data}.evaluate(); // TODO necessary? evaluators should be used outside of serializable
  ls::std::core::type::byte_field searchText = _data;

  while (!searchText.empty() && searchText != ls::std::io::NewLine::get())
  {
    ::std::string::size_type positionOfNewLine = searchText.find(ls::std::io::NewLine::get());
    ::std::string line = ls::std::io::SerializableSectionPairRowListValue::_getLine(positionOfNewLine, searchText);
    line = line.substr(2);
    this->value->add(line);
    ls::std::io::SerializableSectionPairRowListValue::_updateSearchText(positionOfNewLine, searchText);
  }
}

::std::string ls::std::io::SerializableSectionPairRowListValue::_getLine(::std::string::size_type _position, const ls::std::core::type::byte_field &_searchText)
{
  ::std::string line{};

  if (_position != ::std::string::npos)
  {
    line = _searchText.substr(0, _position + (ls::std::io::NewLine::get().size() - 1));
  }
  else
  {
    line = _searchText;
  }

  return line;
}

void ls::std::io::SerializableSectionPairRowListValue::_setValue(const ::std::shared_ptr<ls::std::io::SectionPairRowListValue> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value}.evaluate();
  this->value = _value;
}

void ls::std::io::SerializableSectionPairRowListValue::_updateSearchText(::std::string::size_type _position, ls::std::core::type::byte_field &_searchText)
{
  if (_position != ::std::string::npos)
  {
    _searchText = _searchText.substr(_position + ls::std::io::NewLine::get().size());
  }
  else
  {
    _searchText = "";
  }
}
