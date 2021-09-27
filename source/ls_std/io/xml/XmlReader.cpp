/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/xml/XmlReader.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/io/xml/XmlParser.hpp>

ls_std::XmlReader::XmlReader(const std::shared_ptr<ls_std::XmlDocument> &_document, const std::string &_absolutePath)
    : ls_std::Class("XmlReader"),
      xmlFile(ls_std::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls_std::File{_absolutePath});
}

ls_std::byte_field ls_std::XmlReader::read()
{
  ls_std::byte_field data = ls_std::FileReader{this->xmlFile}.read();
  ls_std::XmlParser{this->document}.parse(data);

  return data;
}

std::shared_ptr<ls_std::XmlDocument> ls_std::XmlReader::getDocument()
{
  return this->document;
}

void ls_std::XmlReader::setDocument(const std::shared_ptr<ls_std::XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::XmlReader::setFile(const ls_std::File &_xmlFile)
{
  this->_assignFile(_xmlFile);
}

void ls_std::XmlReader::_assignDocument(const std::shared_ptr<ls_std::XmlDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls_std::XmlReader::_assignFile(ls_std::File _xmlFile)
{
  if (!_xmlFile.exists())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->xmlFile = _xmlFile;
}
