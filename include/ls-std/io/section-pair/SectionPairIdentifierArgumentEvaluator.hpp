/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-09
*
* */

#ifndef LS_STD_SECTION_PAIR_IDENTIFIER_ARGUMENT_EVALUATOR_HPP
#define LS_STD_SECTION_PAIR_IDENTIFIER_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <string>

namespace ls::std::io
{
  class SectionPairIdentifierArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      SectionPairIdentifierArgumentEvaluator(::std::string _identifier, ::std::string _message);
      ~SectionPairIdentifierArgumentEvaluator() override;

      void evaluate() override;

    private:

      ::std::string identifier{};
      ::std::string message{};
  };
}

#endif
