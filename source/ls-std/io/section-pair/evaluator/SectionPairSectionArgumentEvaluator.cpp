/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-20
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairSectionArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>

ls::std::io::SectionPairSectionArgumentEvaluator::SectionPairSectionArgumentEvaluator(::std::string _section) : ls::std::core::Class("SectionPairSectionArgumentEvaluator"), section(::std::move(_section))
{}

ls::std::io::SectionPairSectionArgumentEvaluator::~SectionPairSectionArgumentEvaluator() = default;

void ls::std::io::SectionPairSectionArgumentEvaluator::evaluate()
{
  if (!ls::std::io::SectionPairSectionValidator{this->section}.isValid())
  {
    ::std::string message = "\"" + this->section + "\" is not a valid section!";
    throw ls::std::core::IllegalArgumentException{message};
  }
}
