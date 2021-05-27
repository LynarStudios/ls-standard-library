/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/kv/KvReader.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/io/kv/KvParser.hpp>

ls_std::KvReader::KvReader(const std::shared_ptr<ls_std::KvDocument> &_document, const std::string &_absolutePath)
    : ls_std::Class("KvReader"),
      kvFile(ls_std::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls_std::File{_absolutePath});
}

ls_std::byte_field ls_std::KvReader::read()
{
  ls_std::byte_field data = ls_std::FileReader{this->kvFile}.read();
  ls_std::KvParser{this->document}.parse(data);

  return data;
}

std::shared_ptr<ls_std::KvDocument> ls_std::KvReader::getDocument()
{
  return this->document;
}

void ls_std::KvReader::setDocument(const std::shared_ptr<ls_std::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::KvReader::setFile(const ls_std::File &_kvFile)
{
  this->_assignFile(_kvFile);
}

void ls_std::KvReader::_assignDocument(const std::shared_ptr<ls_std::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls_std::KvReader::_assignFile(ls_std::File _kvFile)
{
  if (!_kvFile.exists())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->kvFile = _kvFile;
}
