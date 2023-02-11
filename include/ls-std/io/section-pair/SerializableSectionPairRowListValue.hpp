/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-11
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_LIST_VALUE_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_LIST_VALUE_HPP

#include "SectionPairRowListValue.hpp"
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SerializableSectionPairRowListValue : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SerializableSectionPairRowListValue(const ::std::shared_ptr<ls::std::io::SectionPairRowListValue>& _value);
      ~SerializableSectionPairRowListValue() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairRowListValue> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::io::SectionPairRowListValue> value{};

      [[nodiscard]] static ::std::string _getLine(::std::string::size_type _position, const ls::std::core::type::byte_field &_searchText);
      void _setValue(const ::std::shared_ptr<ls::std::io::SectionPairRowListValue>& _value);
      static void _updateSearchText(::std::string::size_type _position, ls::std::core::type::byte_field &_searchText);
  };
}

#endif
