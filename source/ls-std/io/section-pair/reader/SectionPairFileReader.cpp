/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
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

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::IllegalArgumentException;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileExistenceEvaluator;
using ls::std::io::FileReader;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairFileExtensionValidator;
using ls::std::io::SectionPairFileReader;
using ls::std::io::SectionPairFileReaderParameter;
using std::make_shared;
using std::shared_ptr;
using std::string;

SectionPairFileReader::SectionPairFileReader(const SectionPairFileReaderParameter &_parameter) : Class("SectionPairFileReader")
{
  this->parameter = _parameter;
  ConditionalFunctionExecutor{this->parameter.getFileExistenceEvaluator() == nullptr}.execute([this] { _createFileExistenceEvaluator(); });
  this->parameter.getFileExistenceEvaluator()->evaluate();
  this->_checkFileExtension();
  ConditionalFunctionExecutor{this->parameter.getReader() == nullptr}.execute([this] { _createReader(); });
  ConditionalFunctionExecutor{this->parameter.getDocument() == nullptr}.execute([this] { _createDocument(); });
}

SectionPairFileReader::~SectionPairFileReader() noexcept = default;

shared_ptr<SectionPairDocument> SectionPairFileReader::getDocument()
{
  return this->parameter.getDocument();
}

byte_field SectionPairFileReader::read()
{
  this->parameter.getDocument()->clear();
  byte_field data = this->parameter.getReader()->read();
  this->parameter.getDocument()->unmarshal(data);

  return data;
}

void SectionPairFileReader::_checkFileExtension()
{
  if (!SectionPairFileExtensionValidator{this->parameter.getFilePath()}.isValid())
  {
    string message = "\"" + this->parameter.getFilePath() + "\" does not have a valid section pair file extension (.txt or .sp)!";
    throw IllegalArgumentException{message};
  }
}

void SectionPairFileReader::_createDocument()
{
  this->parameter.setDocument(make_shared<SectionPairDocument>());
}

void SectionPairFileReader::_createFileExistenceEvaluator()
{
  this->parameter.setFileExistenceEvaluator(make_shared<FileExistenceEvaluator>(this->parameter.getFilePath()));
}

void SectionPairFileReader::_createReader()
{
  File file{this->parameter.getFilePath()};
  this->parameter.setReader(make_shared<FileReader>(file));
}
