/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_DOCUMENT_HPP
#define LS_STD_SECTION_PAIR_DOCUMENT_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/io/section-pair/type/SectionPairDocumentTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairDocument : public ::std::enable_shared_from_this<SectionPairDocument>, public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
  {
    public:

      SectionPairDocument();
      ~SectionPairDocument() noexcept override;

      void add(const section_pair_document_section_list_element &_section);
      void clear();
      [[nodiscard]] section_pair_document_section_list_element get(size_t _index);
      [[nodiscard]] size_t getAmountOfSections();
      [[nodiscard]] ::std::string getHeader();
      [[nodiscard]] section_pair_document_section_list getSectionList();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void reserveNewLine(const ::std::string &_reservedNewLine);
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      const ::std::string header = "# section-pair document";
      ::std::string reservedNewLine{};
      ls::std::io::section_pair_document_section_list sections{};
      ::std::shared_ptr<ls::std::core::interface_type::ISerializable> serializable{};

      void _checkSectionExistence(const ls::std::io::section_pair_identifier &_sectionId);
      void _createSerializable();
      [[nodiscard]] bool _hasSection(const ls::std::io::section_pair_identifier &_identifier);
  };
}

#endif
