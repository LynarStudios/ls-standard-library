/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_IDENTIFIER_ARGUMENT_EVALUATOR_HPP
#define LS_STD_SECTION_PAIR_IDENTIFIER_ARGUMENT_EVALUATOR_HPP

#include "SectionPairTypes.hpp"
#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairIdentifierArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit SectionPairIdentifierArgumentEvaluator(ls::std::io::section_pair_identifier _identifier, ::std::string _message);
      ~SectionPairIdentifierArgumentEvaluator() override;

      void evaluate() override;

    private:

      ls::std::io::section_pair_identifier identifier{};
      ::std::string message{};
  };
}

#endif
