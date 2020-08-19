/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-19
 *
 * */

#include "StorableFile.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"

ls_std::StorableFile::StorableFile(const std::string &_path)
{
  this->_init(_path);
}

std::string ls_std::StorableFile::getContent()
{
  return this->content;
}

void ls_std::StorableFile::load()
{
  ls_std::FileReader reader {*this->file};
  ls_std::byte* data = reader.read();
  this->content = {data, (size_t) this->file->getSize()};
}

void ls_std::StorableFile::reset(const std::string &_path)
{
  this->_init(_path);
}

void ls_std::StorableFile::save()
{
  ls_std::FileWriter writer {*this->file};
  writer.write(this->content.c_str());
}

void ls_std::StorableFile::setContent(const std::string &_content)
{
  this->content = _content;
}

void ls_std::StorableFile::_init(const std::string &_path)
{
  if(this->file == nullptr) {
    this->file = std::make_shared<ls_std::File>(_path);
  } else {
    this->file->reset(_path);
  }
}
