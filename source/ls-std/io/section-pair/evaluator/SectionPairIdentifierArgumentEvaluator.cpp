/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-17
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>

ls::std::io::SectionPairIdentifierArgumentEvaluator::SectionPairIdentifierArgumentEvaluator(ls::std::io::section_pair_identifier _identifier, ::std::string _message) : ls::std::core::Class("SectionPairIdentifierArgumentEvaluator"), identifier(::std::move(_identifier)), message(::std::move(_message))
{}

ls::std::io::SectionPairIdentifierArgumentEvaluator::~SectionPairIdentifierArgumentEvaluator() = default;

void ls::std::io::SectionPairIdentifierArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairIdentifierValidator{this->identifier}.isValid())
  {
    throw ls::std::core::IllegalArgumentException{this->message};
  }
}
