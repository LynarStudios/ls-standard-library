/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-11-26
 *
 * */

#include <fstream>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/exception/FileNotFoundException.hpp>
#include <ls_std/exception/FileOperationException.hpp>

ls_std::FileReader::FileReader(ls_std::File &_file) : ls_std::Class("FileReader"),
file(_file)
{
  ls_std::FileReader::_init(_file);
}

ls_std::byte_field ls_std::FileReader::read()
{
  ls_std::byte* data;
  std::ifstream inputStream {this->file.getAbsoluteFilePath(), std::ifstream::binary};
  int length = (int) this->file.getSize();
  data = new ls_std::byte[length];
  inputStream.read(data, length);

  if(!inputStream) {
    throw ls_std::FileOperationException {};
  }

  inputStream.close();
  ls_std::byte_field readData = ls_std::byte_field {data, (size_t) this->file.getSize()};
  delete[] data;

  return readData;
}

void ls_std::FileReader::reset(ls_std::File &_file)
{
  ls_std::FileReader::_init(_file);
  this->file = _file;
}

void ls_std::FileReader::_init(ls_std::File &_file)
{
  if(!_file.exists()) {
    throw ls_std::FileNotFoundException {};
  }
}
