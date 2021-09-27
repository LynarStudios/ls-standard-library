/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2021-09-18
 *
 * */

#include <fstream>
#include <ls_std/io/FileWriter.hpp>
#include <ls_std/exception/FileNotFoundException.hpp>
#include <ls_std/exception/FileOperationException.hpp>

ls_std::FileWriter::FileWriter(ls_std::File &_file)
    : ls_std::Class("FileWriter"),
      file(_file)
{
  ls_std::FileWriter::_init(_file);
}

void ls_std::FileWriter::reset(ls_std::File &_file)
{
  ls_std::FileWriter::_init(_file);
  this->file = _file;
}

bool ls_std::FileWriter::write(const ls_std::byte_field &_data)
{
  std::ofstream outputStream{};
  outputStream.open(this->file.getAbsoluteFilePath());
  outputStream << _data;

  return !outputStream.fail();
}

void ls_std::FileWriter::_init(ls_std::File &_file)
{
  if (!_file.exists())
  {
    throw ls_std::FileNotFoundException{};
  }
}
