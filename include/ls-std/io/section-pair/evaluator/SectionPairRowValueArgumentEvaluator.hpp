/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-11
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_VALUE_ARGUMENT_EVALUATOR_HPP
#define LS_STD_SECTION_PAIR_ROW_VALUE_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowValueArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit SectionPairRowValueArgumentEvaluator(ls::std::io::section_pair_row_value _value, ::std::string _message);
      ~SectionPairRowValueArgumentEvaluator() override;

      void evaluate() override;

    private:

      ::std::string message{};
      ls::std::io::section_pair_row_value value{};
  };
}

#endif
