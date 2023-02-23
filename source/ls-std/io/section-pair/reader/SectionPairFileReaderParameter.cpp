/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/reader/SectionPairFileReaderParameter.hpp>

using ls::std::core::interface_type::IEvaluator;
using ls::std::core::interface_type::IReader;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairFileReaderParameter;
using std::shared_ptr;
using std::string;

SectionPairFileReaderParameter::SectionPairFileReaderParameter() = default;

SectionPairFileReaderParameter::~SectionPairFileReaderParameter() = default;

shared_ptr<SectionPairDocument> SectionPairFileReaderParameter::getDocument()
{
  return this->document;
}

shared_ptr<IEvaluator> SectionPairFileReaderParameter::getFileExistenceEvaluator()
{
  return this->fileExistenceEvaluator;
}

string SectionPairFileReaderParameter::getFilePath()
{
  return this->filePath;
}

shared_ptr<IReader> SectionPairFileReaderParameter::getReader()
{
  return this->reader;
}

void SectionPairFileReaderParameter::setDocument(const shared_ptr<SectionPairDocument> &_document)
{
  this->document = _document;
}

void SectionPairFileReaderParameter::setFileExistenceEvaluator(const shared_ptr<IEvaluator> &_fileExistenceEvaluator)
{
  this->fileExistenceEvaluator = _fileExistenceEvaluator;
}

void SectionPairFileReaderParameter::setFilePath(const string &_filePath)
{
  this->filePath = _filePath;
}

void SectionPairFileReaderParameter::setReader(const shared_ptr<IReader> &_reader)
{
  this->reader = _reader;
}
