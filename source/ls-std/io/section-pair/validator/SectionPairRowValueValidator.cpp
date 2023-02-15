/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-15
*
* */

#include <ls-std/io/section-pair/validator/SectionPairRowValueValidator.hpp>

ls::std::io::SectionPairRowValueValidator::SectionPairRowValueValidator(ls::std::io::section_pair_row_value _value) : ls::std::core::Class("SectionPairRowValueValidator"), value(::std::move(_value))
{}

ls::std::io::SectionPairRowValueValidator::~SectionPairRowValueValidator() = default;

bool ls::std::io::SectionPairRowValueValidator::isValid()
{
  size_t foundPosition = this->value.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-0123456789_#![]{}()/$€§%?<>+:;., *\"\n\r");
  return foundPosition == ls::std::io::section_pair_row_value::npos;
}
