/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/kv/KvFileReader.hpp>
#include <ls-std/io/kv/KvParser.hpp>

ls::std::io::KvFileReader::KvFileReader(const ::std::shared_ptr<ls::std::io::KvDocument> &_document, const ::std::string &_absolutePath)
    : ls::std::core::Class("KvFileReader"),
      kvFile(ls::std::io::File{""})
{
  this->_assignDocument(_document);
  this->_assignFile(ls::std::io::File{_absolutePath});
}

ls::std::io::KvFileReader::~KvFileReader() = default;

ls::std::core::type::byte_field ls::std::io::KvFileReader::read()
{
  ls::std::core::type::byte_field data = ls::std::io::FileReader{this->kvFile}.read();
  ls::std::io::KvParser{this->document}.parse(data);

  return data;
}

::std::shared_ptr<ls::std::io::KvDocument> ls::std::io::KvFileReader::getDocument()
{
  return this->document;
}

void ls::std::io::KvFileReader::setDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::std::io::KvFileReader::setFile(const ls::std::io::File &_kvFile)
{
  this->_assignFile(_kvFile);
}

void ls::std::io::KvFileReader::_assignDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

void ls::std::io::KvFileReader::_assignFile(ls::std::io::File _kvFile)
{
  if (!_kvFile.exists())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->kvFile = _kvFile;
}
