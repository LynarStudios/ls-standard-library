/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-22
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowSingleValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>

ls::std::io::SectionPairRowSingleValueArgumentEvaluator::SectionPairRowSingleValueArgumentEvaluator(::std::string _singleValueRow) : ls::std::core::Class("SectionPairRowSingleValueArgumentEvaluator"), singleValueRow(::std::move(_singleValueRow))
{}

ls::std::io::SectionPairRowSingleValueArgumentEvaluator::~SectionPairRowSingleValueArgumentEvaluator() = default;

void ls::std::io::SectionPairRowSingleValueArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairRowSingleValueValidator{this->singleValueRow}.isValid())
  {
    ::std::string message = "\"" + this->singleValueRow + "\" is not a valid section pair single value row!";
    throw ls::std::core::IllegalArgumentException{ls::std::io::SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
