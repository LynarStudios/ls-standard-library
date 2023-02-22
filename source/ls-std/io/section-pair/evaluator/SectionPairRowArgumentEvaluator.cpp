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
#include <ls-std/io/section-pair/evaluator/SectionPairRowArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <string>

ls::std::io::SectionPairRowArgumentEvaluator::SectionPairRowArgumentEvaluator(::std::string _sectionPairRow) : ls::std::core::Class("SectionPairRowArgumentEvaluator"), sectionPairRow(::std::move(_sectionPairRow))
{}

ls::std::io::SectionPairRowArgumentEvaluator::~SectionPairRowArgumentEvaluator() noexcept = default;

void ls::std::io::SectionPairRowArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairRowValidator{this->sectionPairRow}.isValid())
  {
    ::std::string message = "\"" + this->sectionPairRow + "\" is not a valid section pair row!";
    throw ls::std::core::IllegalArgumentException{ls::std::io::SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
