/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <ls-std/io/section-pair/reader/SectionPairFileReaderParameter.hpp>

ls::std::io::SectionPairFileReaderParameter::SectionPairFileReaderParameter() = default;

ls::std::io::SectionPairFileReaderParameter::~SectionPairFileReaderParameter() = default;

::std::shared_ptr<ls::std::io::SectionPairDocument> ls::std::io::SectionPairFileReaderParameter::getDocument()
{
  return this->document;
}

::std::string ls::std::io::SectionPairFileReaderParameter::getFilePath()
{
  return this->filePath;
}

::std::shared_ptr<ls::std::core::interface_type::IReader> ls::std::io::SectionPairFileReaderParameter::getReader()
{
  return this->reader;
}

void ls::std::io::SectionPairFileReaderParameter::setDocument(const ::std::shared_ptr<ls::std::io::SectionPairDocument> &_document)
{
  this->document = _document;
}

void ls::std::io::SectionPairFileReaderParameter::setFilePath(const ::std::string &_filePath)
{
  this->filePath = _filePath;
}

void ls::std::io::SectionPairFileReaderParameter::setReader(const ::std::shared_ptr<core::interface_type::IReader> &_reader)
{
  this->reader = _reader;
}
