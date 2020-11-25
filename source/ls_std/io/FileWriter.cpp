/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-11-25
 *
 * */

#include <fstream>
#include <ls_std/io/FileWriter.hpp>
#include <ls_std/exception/FileNotFoundException.hpp>
#include <ls_std/exception/FileOperationException.hpp>

ls_std::FileWriter::FileWriter(ls_std::File &_file) : Class("FileWriter"),
file(_file)
{
  ls_std::FileWriter::_init(_file);
}

void ls_std::FileWriter::reset(File &_file)
{
  ls_std::FileWriter::_init(_file);
  this->file = _file;
}

bool ls_std::FileWriter::write(const ls_std::byte_field& _data)
{
  std::ofstream outputStream {};
  outputStream.open(this->file.getAbsoluteFilePath());
  bool succeeded;

  if(outputStream << _data) {
    succeeded = true;
  } else {
    throw ls_std::FileOperationException {};
  }

  outputStream.close();
  return succeeded;
}

void ls_std::FileWriter::_init(File &_file)
{
  if(!_file.exists()) {
    throw ls_std::FileNotFoundException {};
  }
}
