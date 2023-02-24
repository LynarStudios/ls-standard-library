/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowListValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairRowListValueArgumentEvaluator;
using ls::std::io::SectionPairRowListValueValidator;
using std::move;
using std::string;

SectionPairRowListValueArgumentEvaluator::SectionPairRowListValueArgumentEvaluator(string _listValueRow) : Class("SectionPairRowListValueArgumentEvaluator"), listValueRow(::move(_listValueRow))
{}

SectionPairRowListValueArgumentEvaluator::~SectionPairRowListValueArgumentEvaluator() noexcept = default;

void SectionPairRowListValueArgumentEvaluator::evaluate()
{
  if (!SectionPairRowListValueValidator{this->listValueRow}.isValid())
  {
    string message = "\"" + this->listValueRow + "\" is not a valid section pair list value row!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
