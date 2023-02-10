/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_HPP

#include "SectionPairRowValue.hpp"
#include "SectionPairTypes.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowSingleValue : public ls::std::core::Class, public ls::std::io::SectionPairRowValue
  {
    public:

      explicit SectionPairRowSingleValue(const ls::std::io::section_pair_row_value &_value);
      ~SectionPairRowSingleValue() override;

      [[nodiscard]] ls::std::io::section_pair_row_value get();
      [[nodiscard]] ls::std::io::SectionPairRowEnumType getType() override;
      void set(const ls::std::io::section_pair_row_value &_value);

    private:

      ls::std::io::section_pair_row_value value{};

      void _set(const ls::std::io::section_pair_row_value &_value);
  };
}

#endif
