/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-18
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_HPP
#define LS_STD_SECTION_PAIR_SECTION_HPP

#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/type/SectionPairSectionTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairSection : public ::std::enable_shared_from_this<SectionPairSection>, public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SectionPairSection(const ls::std::io::section_pair_identifier &_sectionId);
      ~SectionPairSection() override;

      void add(const section_pair_row_list_element &_row);
      void clear();
      [[nodiscard]] section_pair_row_list_element get(size_t _index);
      [[nodiscard]] ls::std::io::section_pair_row_list getList();
      [[nodiscard]] size_t getRowAmount();
      [[nodiscard]] ls::std::io::section_pair_identifier getSectionId();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void reserveNewLine(const ::std::string &_reservedNewLine);
      void setSectionId(const ls::std::io::section_pair_identifier &_sectionId);
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::string reservedNewLine{};
      ls::std::io::section_pair_row_list rows{};
      ls::std::io::section_pair_identifier sectionId{};
      ::std::shared_ptr<ls::std::core::interface_type::ISerializable> serializable{};

      void _createSerializable();
      [[nodiscard]] bool _hasRow(const ls::std::io::section_pair_identifier &_key);
      void _rowExistenceCheck(const ls::std::io::section_pair_identifier &_key);
      void _setSectionId(const ls::std::io::section_pair_identifier &_sectionId);
  };
}

#endif
