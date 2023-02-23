/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/model/SectionPairRowValue.hpp>

using ls::std::core::type::byte_field;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowValue;
using std::string;

SectionPairRowValue::SectionPairRowValue(const SectionPairRowEnumType &_type) : type(_type)
{}

SectionPairRowValue::~SectionPairRowValue() noexcept = default;

byte_field SectionPairRowValue::marshal()
{
  return byte_field{};
}

void SectionPairRowValue::reserveNewLine(const string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void SectionPairRowValue::unmarshal(const byte_field &_data)
{}
