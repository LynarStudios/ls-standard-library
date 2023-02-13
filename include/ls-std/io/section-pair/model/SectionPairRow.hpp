/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-13
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_HPP
#define LS_STD_SECTION_PAIR_ROW_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairRowEnumType.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowValue.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRow : public ::std::enable_shared_from_this<SectionPairRow>, public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SectionPairRow(const ls::std::io::section_pair_identifier &_key, const ls::std::io::SectionPairRowEnumType &_type);
      ~SectionPairRow() override;

      [[nodiscard]] ls::std::io::section_pair_identifier getKey();
      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairRowValue> getValue();
      [[nodiscard]] bool isList();
      [[nodiscard]] bool isSingleValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void setKey(const ls::std::io::section_pair_identifier &_key);
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ls::std::io::section_pair_identifier key{};
      ::std::shared_ptr<ls::std::core::interface_type::ISerializable> serializable{};
      ::std::shared_ptr<ls::std::io::SectionPairRowValue> value{};

      void _createSerializable();
      void _initValue(const ls::std::io::SectionPairRowEnumType &_type);
      void _setKey(const ls::std::io::section_pair_identifier &_key);
  };
}

#endif
