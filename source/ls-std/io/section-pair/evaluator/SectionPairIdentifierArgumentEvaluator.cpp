/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <string>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::section_pair_identifier;
using ls::std::io::SectionPairIdentifierArgumentEvaluator;
using ls::std::io::SectionPairIdentifierValidator;
using ls::std::io::SectionPairMessageFormatter;
using std::move;
using std::string;

SectionPairIdentifierArgumentEvaluator::SectionPairIdentifierArgumentEvaluator(section_pair_identifier _identifier) : Class("SectionPairIdentifierArgumentEvaluator"), identifier(::move(_identifier))
{}

SectionPairIdentifierArgumentEvaluator::~SectionPairIdentifierArgumentEvaluator() noexcept = default;

void SectionPairIdentifierArgumentEvaluator::evaluate()
{
  if (!SectionPairIdentifierValidator{this->identifier}.isValid())
  {
    string message = "\"" + this->identifier + "\" is not a valid identifier!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
