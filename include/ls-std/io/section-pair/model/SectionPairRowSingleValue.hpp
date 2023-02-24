/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_HPP

#include "SectionPairRowValue.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowSingleValue : public ::std::enable_shared_from_this<SectionPairRowSingleValue>, public ls::std::core::Class, public ls::std::io::SectionPairRowValue
  {
    public:

      explicit SectionPairRowSingleValue(const ls::std::io::section_pair_row_value &_value);
      ~SectionPairRowSingleValue() noexcept override;

      [[nodiscard]] ls::std::io::section_pair_row_value get();
      [[nodiscard]] ls::std::io::SectionPairRowEnumType getType() override;
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void set(const ls::std::io::section_pair_row_value &_value);
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::core::interface_type::ISerializable> serializable{};
      ls::std::io::section_pair_row_value value{};

      void _createSerializable();
      void _set(const ls::std::io::section_pair_row_value &_value);
  };
}

#endif
