/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_LIST_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_LIST_VALUE_HPP

#include "SectionPairRowValue.hpp"
#include "SectionPairTypes.hpp"
#include <list>
#include <ls-std/core/Class.hpp>

namespace ls::std::io
{
  class SectionPairRowListValue : public ls::std::core::Class, public ls::std::io::SectionPairRowValue
  {
    public:

      SectionPairRowListValue();
      ~SectionPairRowListValue() override;

      void add(const ls::std::io::section_pair_row_value &_value);
      [[nodiscard]] ls::std::io::section_pair_row_value get(size_t _index);
      [[nodiscard]] size_t getSize();
      [[nodiscard]] ls::std::io::SectionPairRowEnumType getType() override;

    private:

      ::std::list<ls::std::io::section_pair_row_value> values{};
  };
}

#endif
