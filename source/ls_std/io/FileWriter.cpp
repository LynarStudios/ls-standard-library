/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-12
 *
 * */

#include <fstream>
#include <ls_std/io/FileWriter.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>

ls::std::io::FileWriter::FileWriter(ls::std::io::File &_file)
    : ls::std::core::Class("FileWriter"),
      file(_file)
{
  ls::std::io::FileWriter::_init(_file);
}

void ls::std::io::FileWriter::reset(ls::std::io::File &_file)
{
  ls::std::io::FileWriter::_init(_file);
  this->file = _file;
}

bool ls::std::io::FileWriter::write(const ls::std::core::type::byte_field &_data)
{
  ::std::ofstream outputStream{};
  outputStream.open(this->file.getAbsoluteFilePath());
  outputStream << _data;

  return !outputStream.fail();
}

void ls::std::io::FileWriter::_init(ls::std::io::File &_file)
{
  if (!_file.exists())
  {
    throw ls::std::core::FileNotFoundException{};
  }
}
