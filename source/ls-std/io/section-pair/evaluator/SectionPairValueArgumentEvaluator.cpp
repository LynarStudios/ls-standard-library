/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairValueArgumentEvaluator;
using ls::std::io::SectionPairValueValidator;
using std::move;
using std::string;

SectionPairValueArgumentEvaluator::SectionPairValueArgumentEvaluator(section_pair_row_value _value) : Class("SectionPairValueArgumentEvaluator"), value(::move(_value))
{}

SectionPairValueArgumentEvaluator::~SectionPairValueArgumentEvaluator() noexcept = default;

void SectionPairValueArgumentEvaluator::evaluate()
{
  if (!SectionPairValueValidator(this->value).isValid())
  {
    string message = "\"" + this->value + "\" is not a valid value!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
