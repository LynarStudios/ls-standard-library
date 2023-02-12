/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-12
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_HPP

#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class SerializableSectionPairRow : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SerializableSectionPairRow(const ::std::shared_ptr<ls::std::io::SectionPairRow> &_value);
      ~SerializableSectionPairRow() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairRow> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::io::SectionPairRow> value{};

      [[nodiscard]] ::std::string _marshalKey();
      void _setValue(const ::std::shared_ptr<ls::std::io::SectionPairRow> &_value);
      void _unmarshalListValue(const ls::std::core::type::byte_field &_data);
      void _unmarshalSingleValue(const ls::std::core::type::byte_field &_data);
  };
}

#endif
