/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-14
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_HPP
#define LS_STD_SECTION_PAIR_SECTION_HPP

#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/type/SectionPairSectionTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairSection : public ls::std::core::Class
  {
    public:

      explicit SectionPairSection(const ls::std::io::section_pair_identifier &_sectionId);
      ~SectionPairSection() override;

      void add(const section_pair_row_list_element &_row);
      [[nodiscard]] section_pair_row_list_element get(size_t _index);
      [[nodiscard]] size_t getRowAmount();
      [[nodiscard]] ls::std::io::section_pair_identifier getSectionId();
      void setSectionId(const ls::std::io::section_pair_identifier &_sectionId);

    private:

      ls::std::io::section_pair_row_list rows{};
      ls::std::io::section_pair_identifier sectionId{};

      [[nodiscard]] bool _hasRow(const ls::std::io::section_pair_identifier &_key);
      void _rowExistenceCheck(const ls::std::io::section_pair_identifier &_key);
      void _setSectionId(const ls::std::io::section_pair_identifier &_sectionId);
  };
}

#endif
