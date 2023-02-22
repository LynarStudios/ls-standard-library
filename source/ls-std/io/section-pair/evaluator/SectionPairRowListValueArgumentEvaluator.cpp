/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-22
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowListValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>

ls::std::io::SectionPairRowListValueArgumentEvaluator::SectionPairRowListValueArgumentEvaluator(::std::string _listValueRow) : ls::std::core::Class("SectionPairRowListValueArgumentEvaluator"), listValueRow(::std::move(_listValueRow))
{}

ls::std::io::SectionPairRowListValueArgumentEvaluator::~SectionPairRowListValueArgumentEvaluator() = default;

void ls::std::io::SectionPairRowListValueArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairRowListValueValidator{this->listValueRow}.isValid())
  {
    ::std::string message = "\"" + this->listValueRow + "\" is not a valid section pair list value row!";
    throw ls::std::core::IllegalArgumentException{ls::std::io::SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
