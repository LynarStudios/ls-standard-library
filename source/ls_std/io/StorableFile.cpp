/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/StorableFile.hpp>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/io/FileWriter.hpp>

ls::StorableFile::StorableFile(const ::std::string &_path)
{
  this->_init(_path);
}

std::shared_ptr<ls::File> ls::StorableFile::getFile()
{
  return this->file;
}

ls::std::core::byte_field ls::StorableFile::load()
{
  ls::FileReader reader{*this->file};
  return reader.read();
}

void ls::StorableFile::reset(const ::std::string &_path)
{
  this->_init(_path);
}

void ls::StorableFile::save(const ls::std::core::byte_field &_data)
{
  ls::FileWriter writer{*this->file};
  writer.write(_data);
}

void ls::StorableFile::_init(const ::std::string &_path)
{
  if (this->file == nullptr)
  {
    this->file = ::std::make_shared<ls::File>(_path);
  }
  else
  {
    this->file->reset(_path);
  }
}
