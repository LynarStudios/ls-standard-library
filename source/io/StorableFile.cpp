/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-25
 *
 * */

#include "StorableFile.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"

ls_std::StorableFile::StorableFile(const std::string &_path)
{
  this->_init(_path);
}

std::shared_ptr<ls_std::File> ls_std::StorableFile::getFile()
{
  return this->file;
}

ls_std::byte_field ls_std::StorableFile::load()
{
  ls_std::FileReader reader {*this->file};
  return reader.read();
}

void ls_std::StorableFile::reset(const std::string &_path)
{
  this->_init(_path);
}

void ls_std::StorableFile::save(const ls_std::byte_field& _data)
{
  ls_std::FileWriter writer {*this->file};
  writer.write(_data);
}

void ls_std::StorableFile::_init(const std::string &_path)
{
  if(this->file == nullptr) {
    this->file = std::make_shared<ls_std::File>(_path);
  } else {
    this->file->reset(_path);
  }
}
