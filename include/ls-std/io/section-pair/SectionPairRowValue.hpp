/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_VALUE_HPP

#include "SectionPairRowEnumType.hpp"
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowValue
  {
    public:

      explicit SectionPairRowValue(const ls::std::io::SectionPairRowEnumType &_type);
      virtual ~SectionPairRowValue();

      virtual ls::std::io::SectionPairRowEnumType getType() = 0;

    protected:

      ls::std::io::SectionPairRowEnumType type{};
  };
}

#endif
