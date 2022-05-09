/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/xml/XmlReader.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/io/xml/XmlParser.hpp>

ls::XmlReader::XmlReader(const ::std::shared_ptr<ls::XmlDocument> &_document, const ::std::string &_absolutePath)
    : ls::std::core::Class("XmlReader"),
      xmlFile(ls::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls::File{_absolutePath});
}

ls::std::core::byte_field ls::XmlReader::read()
{
  ls::std::core::byte_field data = ls::FileReader{this->xmlFile}.read();
  ls::XmlParser{this->document}.parse(data);

  return data;
}

::std::shared_ptr<ls::XmlDocument> ls::XmlReader::getDocument()
{
  return this->document;
}

void ls::XmlReader::setDocument(const ::std::shared_ptr<ls::XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::XmlReader::setFile(const ls::File &_xmlFile)
{
  this->_assignFile(_xmlFile);
}

void ls::XmlReader::_assignDocument(const ::std::shared_ptr<ls::XmlDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls::XmlReader::_assignFile(ls::File _xmlFile)
{
  if (!_xmlFile.exists())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->xmlFile = _xmlFile;
}
