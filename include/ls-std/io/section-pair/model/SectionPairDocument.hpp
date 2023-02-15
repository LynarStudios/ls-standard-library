/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-15
*
* */

#ifndef LS_STD_SECTION_PAIR_DOCUMENT_HPP
#define LS_STD_SECTION_PAIR_DOCUMENT_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/type/SectionPairDocumentTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairDocument : public ls::std::core::Class
  {
    public:

      SectionPairDocument();
      ~SectionPairDocument() override;

      void add(const section_pair_document_section_list_element &_section);
      [[nodiscard]] section_pair_document_section_list_element get(size_t _index);
      [[nodiscard]] size_t getAmountOfSections();
      [[nodiscard]] section_pair_document_section_list getSectionList();

    private:

      ls::std::io::section_pair_document_section_list sections{};

      void _checkSectionExistence(const ls::std::io::section_pair_identifier &_sectionId);
      [[nodiscard]] bool _hasSection(const ls::std::io::section_pair_identifier &_identifier);
  };
}

#endif
