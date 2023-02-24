/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/FileWriter.hpp>
#include <ls-std/io/StorableFile.hpp>

using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileReader;
using ls::std::io::FileWriter;
using ls::std::io::StorableFile;
using std::make_shared;
using std::shared_ptr;
using std::string;

StorableFile::StorableFile(const string &_path)
{
  this->_init(_path);
}

StorableFile::~StorableFile() noexcept = default;

shared_ptr<File> StorableFile::getFile()
{
  return this->file;
}

byte_field StorableFile::load()
{
  FileReader reader{*this->file};
  return reader.read();
}

void StorableFile::reset(const string &_path)
{
  this->_init(_path);
}

void StorableFile::save(const byte_field &_data)
{
  FileWriter writer{*this->file};
  writer.write(_data);
}

void StorableFile::_init(const string &_path)
{
  if (this->file == nullptr)
  {
    this->file = make_shared<File>(_path);
  }
  else
  {
    this->file->reset(_path);
  }
}
