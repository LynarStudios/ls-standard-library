/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/io/xml/XMLReader.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/io/xml/XMLParser.hpp>

ls_std::XMLReader::XMLReader(const std::shared_ptr<ls_std::XMLDocument>& _document, const std::string& _absolutePath) : ls_std::Class("XMLReader"),
xmlFile(ls_std::File {""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls_std::File {_absolutePath});
}

ls_std::byte_field ls_std::XMLReader::read()
{
  ls_std::byte_field data = ls_std::FileReader {this->xmlFile}.read();
  ls_std::XMLParser {this->document}.parse(data);

  return data;
}

std::shared_ptr<ls_std::XMLDocument> ls_std::XMLReader::getDocument()
{
  return this->document;
}

void ls_std::XMLReader::setDocument(const std::shared_ptr<ls_std::XMLDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::XMLReader::setFile(const ls_std::File &_xmlFile)
{
  this->_assignFile(_xmlFile);
}

void ls_std::XMLReader::_assignDocument(const std::shared_ptr<ls_std::XMLDocument> &_document)
{
  if(_document == nullptr) {
    throw ls_std::IllegalArgumentException {};
  }

  this->document = _document;
}

void ls_std::XMLReader::_assignFile(ls_std::File _xmlFile)
{
  if(!_xmlFile.exists()) {
    throw ls_std::IllegalArgumentException {};
  }

  this->xmlFile = _xmlFile;
}
