/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/io/StorableFile.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/io/FileWriter.hpp>

ls::std::io::StorableFile::StorableFile(const ::std::string &_path)
{
  this->_init(_path);
}

std::shared_ptr<ls::std::io::File> ls::std::io::StorableFile::getFile()
{
  return this->file;
}

ls::std::core::byte_field ls::std::io::StorableFile::load()
{
  ls::std::io::FileReader reader{*this->file};
  return reader.read();
}

void ls::std::io::StorableFile::reset(const ::std::string &_path)
{
  this->_init(_path);
}

void ls::std::io::StorableFile::save(const ls::std::core::byte_field &_data)
{
  ls::std::io::FileWriter writer{*this->file};
  writer.write(_data);
}

void ls::std::io::StorableFile::_init(const ::std::string &_path)
{
  if (this->file == nullptr)
  {
    this->file = ::std::make_shared<ls::std::io::File>(_path);
  }
  else
  {
    this->file->reset(_path);
  }
}
