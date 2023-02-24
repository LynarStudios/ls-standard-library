/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/xml/XmlParser.hpp>
#include <ls-std/io/xml/XmlReader.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileReader;
using ls::std::io::XmlDocument;
using ls::std::io::XmlParser;
using ls::std::io::XmlReader;
using std::shared_ptr;
using std::string;

XmlReader::XmlReader(const shared_ptr<XmlDocument> &_document, const string &_absolutePath) : Class("XmlReader"), xmlFile(File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(File{_absolutePath});
}

XmlReader::~XmlReader() noexcept = default;

byte_field XmlReader::read()
{
  byte_field data = FileReader{this->xmlFile}.read();
  XmlParser{this->document}.parse(data);

  return data;
}

shared_ptr<XmlDocument> XmlReader::getDocument()
{
  return this->document;
}

void XmlReader::setDocument(const shared_ptr<XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

void XmlReader::setFile(const File &_xmlFile)
{
  this->_assignFile(_xmlFile);
}

void XmlReader::_assignDocument(const shared_ptr<XmlDocument> &_document)
{
  NullPointerArgumentEvaluator{_document, "xml document reference is null!"}.evaluate();
  this->document = _document;
}

void XmlReader::_assignFile(File _xmlFile)
{
  if (!_xmlFile.exists())
  {
    throw IllegalArgumentException{"file does not exist: " + _xmlFile.getAbsoluteFilePath()};
  }

  this->xmlFile = _xmlFile;
}
