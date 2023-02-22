/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-22
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <string>

ls::std::io::SectionPairIdentifierArgumentEvaluator::SectionPairIdentifierArgumentEvaluator(ls::std::io::section_pair_identifier _identifier) : ls::std::core::Class("SectionPairIdentifierArgumentEvaluator"), identifier(::std::move(_identifier))
{}

ls::std::io::SectionPairIdentifierArgumentEvaluator::~SectionPairIdentifierArgumentEvaluator() noexcept = default;

void ls::std::io::SectionPairIdentifierArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairIdentifierValidator{this->identifier}.isValid())
  {
    ::std::string message = "\"" + this->identifier + "\" is not a valid identifier!";
    throw ls::std::core::IllegalArgumentException{ls::std::io::SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
