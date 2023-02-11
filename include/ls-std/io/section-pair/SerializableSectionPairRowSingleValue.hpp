/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-11
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_SINGLE_VALUE_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_SINGLE_VALUE_HPP

#include "SectionPairRowSingleValue.hpp"
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SerializableSectionPairRowSingleValue : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SerializableSectionPairRowSingleValue(const ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue>& _value);
      ~SerializableSectionPairRowSingleValue() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> value{};

      void _setValue(const ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue>& _value);
  };
}

#endif
