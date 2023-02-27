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
#include <ls-std/io/section-pair/evaluator/SectionPairRowArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <string>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairRowArgumentEvaluator;
using ls::std::io::SectionPairRowValidator;
using std::move;
using std::string;

SectionPairRowArgumentEvaluator::SectionPairRowArgumentEvaluator(string _sectionPairRow) : Class("SectionPairRowArgumentEvaluator"), sectionPairRow(::move(_sectionPairRow))
{}

SectionPairRowArgumentEvaluator::~SectionPairRowArgumentEvaluator() noexcept = default;

void SectionPairRowArgumentEvaluator::evaluate()
{
  if (!SectionPairRowValidator{this->sectionPairRow}.isValid())
  {
    string message = "\"" + this->sectionPairRow + "\" is not a valid section pair row!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
