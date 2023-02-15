/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-15
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_SECTION_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_SECTION_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairRowEnumType.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SerializableSectionPairSection : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SerializableSectionPairSection(const ::std::shared_ptr<ls::std::core::Class> &_value);
      ~SerializableSectionPairSection() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::core::Class> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::core::Class> value{};

      static void _checkSectionHeader(const ls::std::core::type::byte_field &_sectionHeader);
      [[nodiscard]] static ls::std::core::type::byte_field _collectSectionRow(const ls::std::core::type::byte_field &_currentRows, ls::std::io::SectionPairRowEnumType &_type);
      [[nodiscard]] static core::type::byte_field _collectSectionListValueRow(const core::type::byte_field &_currentRows, SectionPairRowEnumType &_type);
      [[nodiscard]] static core::type::byte_field _collectSectionSingleValueRow(const ls::std::core::type::byte_field &_firstRow, SectionPairRowEnumType &type);
      [[nodiscard]] static size_t _getNthSubStringPosition(const ls::std::core::type::byte_field &_text, const ls::std::core::type::byte_field &_subText);
      [[nodiscard]] static ls::std::core::type::byte_field _getSectionHeader(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ls::std::core::type::byte_field _getSectionId(const ls::std::core::type::byte_field &_sectionHeader);
      [[nodiscard]] static bool _isListValueRow(const ::std::string &_currentRow);
      [[nodiscard]] static bool _isStartingValueRow(const ::std::string &_currentRow);
      [[nodiscard]] static bool _isSingleValueRow(const ::std::string &_currentRow);
      [[nodiscard]] ls::std::core::type::byte_field _marshalRows();
      [[nodiscard]] ls::std::core::type::byte_field _marshalSectionId();
      void _setValue(const ::std::shared_ptr<ls::std::core::Class> &_value);
      void _unmarshalRow(const ::std::string &_sectionRow, ls::std::io::SectionPairRowEnumType _type);
      void _unmarshalRows(const ls::std::core::type::byte_field &_serializedRows);
      [[nodiscard]] size_t _unmarshalSectionHeader(const ls::std::core::type::byte_field &_data);
  };
}

#endif
