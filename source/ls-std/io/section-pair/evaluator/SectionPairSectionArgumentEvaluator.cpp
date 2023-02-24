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
#include <ls-std/io/section-pair/evaluator/SectionPairSectionArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairSectionArgumentEvaluator;
using ls::std::io::SectionPairSectionValidator;
using std::move;
using std::string;

SectionPairSectionArgumentEvaluator::SectionPairSectionArgumentEvaluator(string _section) : Class("SectionPairSectionArgumentEvaluator"), section(::move(_section))
{}

SectionPairSectionArgumentEvaluator::~SectionPairSectionArgumentEvaluator() noexcept = default;

void SectionPairSectionArgumentEvaluator::evaluate()
{
  if (!SectionPairSectionValidator{this->section}.isValid())
  {
    string message = "\"" + this->section + "\" is not a valid section!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
