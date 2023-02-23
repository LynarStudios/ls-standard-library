/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowSingleValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairRowSingleValueArgumentEvaluator;
using ls::std::io::SectionPairRowSingleValueValidator;
using std::move;
using std::string;

SectionPairRowSingleValueArgumentEvaluator::SectionPairRowSingleValueArgumentEvaluator(string _singleValueRow) : Class("SectionPairRowSingleValueArgumentEvaluator"), singleValueRow(::move(_singleValueRow))
{}

SectionPairRowSingleValueArgumentEvaluator::~SectionPairRowSingleValueArgumentEvaluator() noexcept = default;

void SectionPairRowSingleValueArgumentEvaluator::evaluate()
{
  if (!SectionPairRowSingleValueValidator{this->singleValueRow}.isValid())
  {
    string message = "\"" + this->singleValueRow + "\" is not a valid section pair single value row!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
