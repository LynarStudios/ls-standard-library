/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-17
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_HPP

#include "SerializableSectionPairParameter.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class SerializableSectionPairRow : public ls::std::core::interface_type::ISerializable, public ls::std::core::Class
  {
    public:

      explicit SerializableSectionPairRow(const ls::std::io::SerializableSectionPairParameter &_parameter);
      ~SerializableSectionPairRow() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::core::Class> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ls::std::io::SerializableSectionPairParameter parameter{};

      [[nodiscard]] ::std::string _marshalKey();
      void _unmarshalListValue(const ls::std::core::type::byte_field &_data);
      void _unmarshalSingleValue(const ls::std::core::type::byte_field &_data);
  };
}

#endif
