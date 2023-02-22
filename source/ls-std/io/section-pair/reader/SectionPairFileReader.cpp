/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/io/section-pair/reader/SectionPairFileReader.hpp>
#include <ls-std/io/section-pair/validator/SectionPairFileExtensionValidator.hpp>
#include <memory>

ls::std::io::SectionPairFileReader::SectionPairFileReader(const ls::std::io::SectionPairFileReaderParameter &_parameter) : ls::std::core::Class("SectionPairFileReader")
{
  this->parameter = _parameter;
  ls::std::core::ConditionalFunctionExecutor{this->parameter.getFileExistenceEvaluator() == nullptr}.execute([this] { _createFileExistenceEvaluator(); });
  this->parameter.getFileExistenceEvaluator()->evaluate();
  this->_checkFileExtension();
  ls::std::core::ConditionalFunctionExecutor{this->parameter.getReader() == nullptr}.execute([this] { _createReader(); });
  ls::std::core::ConditionalFunctionExecutor{this->parameter.getDocument() == nullptr}.execute([this] { _createDocument(); });
}

ls::std::io::SectionPairFileReader::~SectionPairFileReader() = default;

::std::shared_ptr<ls::std::io::SectionPairDocument> ls::std::io::SectionPairFileReader::getDocument()
{
  return this->parameter.getDocument();
}

ls::std::core::type::byte_field ls::std::io::SectionPairFileReader::read()
{
  this->parameter.getDocument()->clear();
  ls::std::core::type::byte_field data = this->parameter.getReader()->read();
  this->parameter.getDocument()->unmarshal(data);

  return data;
}

void ls::std::io::SectionPairFileReader::_checkFileExtension()
{
  if (!ls::std::io::SectionPairFileExtensionValidator{this->parameter.getFilePath()}.isValid())
  {
    ::std::string message = "\"" + this->parameter.getFilePath() + "\" does not have a valid section pair file extension (.txt or .sp)!";
    throw ls::std::core::IllegalArgumentException{message};
  }
}

void ls::std::io::SectionPairFileReader::_createDocument()
{
  this->parameter.setDocument(::std::make_shared<ls::std::io::SectionPairDocument>());
}

void ls::std::io::SectionPairFileReader::_createFileExistenceEvaluator()
{
  this->parameter.setFileExistenceEvaluator(::std::make_shared<FileExistenceEvaluator>(this->parameter.getFilePath()));
}

void ls::std::io::SectionPairFileReader::_createReader()
{
  ls::std::io::File file{this->parameter.getFilePath()};
  this->parameter.setReader(::std::make_shared<ls::std::io::FileReader>(file));
}
