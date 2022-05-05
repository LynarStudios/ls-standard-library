/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-05
 *
 * */

#include <fstream>
#include <ls_std/io/FileWriter.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>

ls::FileWriter::FileWriter(ls::File &_file)
    : ls::Class("FileWriter"),
      file(_file)
{
  ls::FileWriter::_init(_file);
}

void ls::FileWriter::reset(ls::File &_file)
{
  ls::FileWriter::_init(_file);
  this->file = _file;
}

bool ls::FileWriter::write(const ls::byte_field &_data)
{
  std::ofstream outputStream{};
  outputStream.open(this->file.getAbsoluteFilePath());
  outputStream << _data;

  return !outputStream.fail();
}

void ls::FileWriter::_init(ls::File &_file)
{
  if (!_file.exists())
  {
    throw ls::FileNotFoundException{};
  }
}
