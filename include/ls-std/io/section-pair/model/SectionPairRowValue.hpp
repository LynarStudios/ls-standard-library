/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-17
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_VALUE_HPP

#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairRowEnumType.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowValue : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SectionPairRowValue(const ls::std::io::SectionPairRowEnumType &_type);
      ~SectionPairRowValue() override;

      virtual ls::std::io::SectionPairRowEnumType getType() = 0;
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void reserveNewLine(const ::std::string &_reservedNewLine);
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    protected:

      ::std::string reservedNewLine{};
      ls::std::io::SectionPairRowEnumType type{};
  };
}

#endif
