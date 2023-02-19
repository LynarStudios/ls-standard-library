/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-19
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>

ls::std::io::SectionPairValueArgumentEvaluator::SectionPairValueArgumentEvaluator(ls::std::io::section_pair_row_value _value, ::std::string _message) : ls::std::core::Class("SectionPairValueArgumentEvaluator"), value(::std::move(_value)), message(::std::move(_message))
{}

ls::std::io::SectionPairValueArgumentEvaluator::~SectionPairValueArgumentEvaluator() = default;

void ls::std::io::SectionPairValueArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairValueValidator(this->value).isValid())
  {
    throw ls::std::core::IllegalArgumentException{this->message};
  }
}
