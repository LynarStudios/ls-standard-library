/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-11
*
* */

#include <ls-std/io/section-pair/model/SectionPairRowValue.hpp>

ls::std::io::SectionPairRowValue::SectionPairRowValue(const ls::std::io::SectionPairRowEnumType &_type) : type(_type)
{}

ls::std::io::SectionPairRowValue::~SectionPairRowValue() = default;

ls::std::core::type::byte_field ls::std::io::SectionPairRowValue::marshal()
{
  return ls::std::core::type::byte_field{};
}

void ls::std::io::SectionPairRowValue::unmarshal(const ls::std::core::type::byte_field &_data)
{}
