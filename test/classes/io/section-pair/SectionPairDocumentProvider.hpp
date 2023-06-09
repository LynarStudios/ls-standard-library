/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-03-27
*
* */

#ifndef LS_STD_SECTION_PAIR_DOCUMENT_PROVIDER_HPP
#define LS_STD_SECTION_PAIR_DOCUMENT_PROVIDER_HPP

#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>
#include <string>

namespace test::io
{
  class SectionPairDocumentProvider
  {
    public:

      SectionPairDocumentProvider();
      ~SectionPairDocumentProvider();

      [[nodiscard]] static ::std::shared_ptr<ls::std::io::SectionPairDocument> createDocument();
      [[nodiscard]] static ls::std::core::type::byte_field createSerializedDocument(const ::std::string &_newLine);
      [[nodiscard]] static ls::std::core::type::byte_field createSerializedDocumentComputerExample(const ::std::string &_newLine);
  };
}

#endif
