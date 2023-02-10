/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_HPP
#define LS_STD_SECTION_PAIR_ROW_HPP

#include "SectionPairRowEnumType.hpp"
#include "SectionPairTypes.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRow : public ls::std::core::Class
  {
    public:

      explicit SectionPairRow(const ls::std::io::section_pair_identifier &_key);
      ~SectionPairRow() override;

      [[nodiscard]] ls::std::io::section_pair_identifier getKey();
      [[nodiscard]] bool isList();
      [[nodiscard]] bool isSingleValue();

    private:

      ls::std::io::section_pair_identifier key{};
      ls::std::io::SectionPairRowEnumType type{};
  };
}

#endif
