/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/kv/KvFileReader.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/io/kv/KvParser.hpp>

ls::KvFileReader::KvFileReader(const std::shared_ptr<ls::KvDocument> &_document, const std::string &_absolutePath)
    : ls::Class("KvFileReader"),
      kvFile(ls::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls::File{_absolutePath});
}

ls::byte_field ls::KvFileReader::read()
{
  ls::byte_field data = ls::FileReader{this->kvFile}.read();
  ls::KvParser{this->document}.parse(data);

  return data;
}

std::shared_ptr<ls::KvDocument> ls::KvFileReader::getDocument()
{
  return this->document;
}

void ls::KvFileReader::setDocument(const std::shared_ptr<ls::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::KvFileReader::setFile(const ls::File &_kvFile)
{
  this->_assignFile(_kvFile);
}

void ls::KvFileReader::_assignDocument(const std::shared_ptr<ls::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls::KvFileReader::_assignFile(ls::File _kvFile)
{
  if (!_kvFile.exists())
  {
    throw ls::IllegalArgumentException{};
  }

  this->kvFile = _kvFile;
}
