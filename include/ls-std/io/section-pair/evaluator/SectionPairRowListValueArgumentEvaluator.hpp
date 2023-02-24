/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_LIST_VALUE_ARGUMENT_EVALUATOR_HPP
#define LS_STD_SECTION_PAIR_ROW_LIST_VALUE_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowListValueArgumentEvaluator : public ls::std::core::Class, public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit SectionPairRowListValueArgumentEvaluator(::std::string _listValueRow);
      ~SectionPairRowListValueArgumentEvaluator() noexcept override;

      void evaluate() override;

    private:

      ::std::string listValueRow{};
  };
}

#endif
