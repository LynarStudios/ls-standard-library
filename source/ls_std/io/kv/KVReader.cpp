/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/kv/KVReader.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/io/kv/KVParser.hpp>

ls_std::KVReader::KVReader(const std::shared_ptr<ls_std::KVDocument> &_document, const std::string &_absolutePath)
    : ls_std::Class("KVReader"),
      kvFile(ls_std::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls_std::File{_absolutePath});
}

ls_std::byte_field ls_std::KVReader::read()
{
  ls_std::byte_field data = ls_std::FileReader{this->kvFile}.read();
  ls_std::KVParser{this->document}.parse(data);

  return data;
}

std::shared_ptr<ls_std::KVDocument> ls_std::KVReader::getDocument()
{
  return this->document;
}

void ls_std::KVReader::setDocument(const std::shared_ptr<ls_std::KVDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::KVReader::setFile(const ls_std::File &_kvFile)
{
  this->_assignFile(_kvFile);
}

void ls_std::KVReader::_assignDocument(const std::shared_ptr<ls_std::KVDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls_std::KVReader::_assignFile(ls_std::File _kvFile)
{
  if (!_kvFile.exists())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->kvFile = _kvFile;
}
