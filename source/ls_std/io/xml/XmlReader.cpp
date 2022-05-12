/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/io/xml/XmlReader.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/io/xml/XmlParser.hpp>

ls::std::io::XmlReader::XmlReader(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document, const ::std::string &_absolutePath)
    : ls::std::core::Class("XmlReader"),
      xmlFile(ls::std::io::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls::std::io::File{_absolutePath});
}

ls::std::core::type::byte_field ls::std::io::XmlReader::read()
{
  ls::std::core::type::byte_field data = ls::std::io::FileReader{this->xmlFile}.read();
  ls::std::io::XmlParser{this->document}.parse(data);

  return data;
}

::std::shared_ptr<ls::std::io::XmlDocument> ls::std::io::XmlReader::getDocument()
{
  return this->document;
}

void ls::std::io::XmlReader::setDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::std::io::XmlReader::setFile(const ls::std::io::File &_xmlFile)
{
  this->_assignFile(_xmlFile);
}

void ls::std::io::XmlReader::_assignDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls::std::io::XmlReader::_assignFile(ls::std::io::File _xmlFile)
{
  if (!_xmlFile.exists())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->xmlFile = _xmlFile;
}
