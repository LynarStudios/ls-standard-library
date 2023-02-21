/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#ifndef LS_STD_SECTION_PAIR_FILE_READER_PARAMETER_HPP
#define LS_STD_SECTION_PAIR_FILE_READER_PARAMETER_HPP

#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairFileReaderParameter
  {
    public:

      SectionPairFileReaderParameter();
      ~SectionPairFileReaderParameter();

      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairDocument> getDocument();
      [[nodiscard]] ::std::string getFilePath();
      void setDocument(const ::std::shared_ptr<ls::std::io::SectionPairDocument> &_document);
      void setFilePath(const ::std::string &_filePath);
      [[nodiscard]] ::std::shared_ptr<ls::std::core::interface_type::IReader> getReader();
      void setReader(const ::std::shared_ptr<core::interface_type::IReader> &_reader);

    private:

      ::std::shared_ptr<ls::std::io::SectionPairDocument> document{};
      ::std::string filePath{};
      ::std::shared_ptr<ls::std::core::interface_type::IReader> reader{};
  };
}

#endif
