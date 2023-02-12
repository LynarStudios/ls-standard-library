/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-12
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_HPP
#define LS_STD_SECTION_PAIR_ROW_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/io/section-pair/SectionPairRowEnumType.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowValue.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRow : public ls::std::core::Class
  {
    public:

      explicit SectionPairRow(const ls::std::io::section_pair_identifier &_key, const ls::std::io::SectionPairRowEnumType &_type);
      ~SectionPairRow() override;

      [[nodiscard]] ls::std::io::section_pair_identifier getKey();
      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairRowValue> getValue();
      [[nodiscard]] bool isList();
      [[nodiscard]] bool isSingleValue();
      void setKey(const ls::std::io::section_pair_identifier &_key);

    private:

      ls::std::io::section_pair_identifier key{};
      ::std::shared_ptr<ls::std::io::SectionPairRowValue> value{};

      void _initValue(const ls::std::io::SectionPairRowEnumType &_type);
      void _setKey(const ls::std::io::section_pair_identifier &_key);
  };
}

#endif
