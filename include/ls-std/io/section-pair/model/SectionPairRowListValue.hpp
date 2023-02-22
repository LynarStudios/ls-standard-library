/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_LIST_VALUE_HPP
#define LS_STD_SECTION_PAIR_ROW_LIST_VALUE_HPP

#include "SectionPairRowValue.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowListValue : public ::std::enable_shared_from_this<SectionPairRowListValue>, public ls::std::core::Class, public ls::std::io::SectionPairRowValue
  {
    public:

      SectionPairRowListValue();
      ~SectionPairRowListValue() override;

      void add(const ls::std::io::section_pair_row_value &_value);
      void clear();
      [[nodiscard]] ls::std::io::section_pair_row_value get(size_t _index);
      [[nodiscard]] ::std::list<ls::std::io::section_pair_row_value> getList();
      [[nodiscard]] size_t getSize();
      [[nodiscard]] ls::std::io::SectionPairRowEnumType getType() override;
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::core::interface_type::ISerializable> serializable{};
      ::std::list<ls::std::io::section_pair_row_value> values{};

      void _createSerializable();
  };
}

#endif
