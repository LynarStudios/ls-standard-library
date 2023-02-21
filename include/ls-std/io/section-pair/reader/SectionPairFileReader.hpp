/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#ifndef LS_STD_SECTION_PAIR_FILE_READER_HPP
#define LS_STD_SECTION_PAIR_FILE_READER_HPP

#include "SectionPairFileReaderParameter.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairFileReader : public ls::std::core::Class, public ls::std::core::interface_type::IReader
  {
    public:

      explicit SectionPairFileReader(const ls::std::io::SectionPairFileReaderParameter &_parameter);
      ~SectionPairFileReader() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::SectionPairDocument> getDocument();
      ls::std::core::type::byte_field read() override; // nodiscard is optional here

    private:

      ls::std::io::SectionPairFileReaderParameter parameter{};

      void _createDocument();
      void _createFileExistenceEvaluator();
      void _createReader();
  };
}

#endif
