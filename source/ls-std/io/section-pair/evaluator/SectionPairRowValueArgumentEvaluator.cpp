/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-17
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValueValidator.hpp>

ls::std::io::SectionPairRowValueArgumentEvaluator::SectionPairRowValueArgumentEvaluator(ls::std::io::section_pair_row_value _value, ::std::string _message) : ls::std::core::Class("SectionPairRowValueArgumentEvaluator"), value(::std::move(_value)), message(::std::move(_message))
{}

ls::std::io::SectionPairRowValueArgumentEvaluator::~SectionPairRowValueArgumentEvaluator() = default;

void ls::std::io::SectionPairRowValueArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairRowValueValidator(this->value).isValid())
  {
    throw ls::std::core::IllegalArgumentException{this->message};
  }
}
