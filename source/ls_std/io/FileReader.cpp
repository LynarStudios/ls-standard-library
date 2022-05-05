/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-05
 *
 * */

#include <fstream>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>

ls::FileReader::FileReader(ls::File &_file)
    : ls::Class("FileReader"),
      file(_file)
{
  ls::FileReader::_init(_file);
}

ls::byte_field ls::FileReader::read()
{
  ls::byte *data;
  std::ifstream inputStream{this->file.getAbsoluteFilePath(), std::ifstream::binary};
  int length = (int) this->file.getSize();
  data = new ls::byte[length];
  inputStream.read(data, length);

  if (inputStream.fail())
  {
    throw ls::FileOperationException{};
  }

  inputStream.close();
  ls::byte_field readData = ls::byte_field{data, (size_t) this->file.getSize()};
  delete[] data;

  return readData;
}

void ls::FileReader::reset(ls::File &_file)
{
  ls::FileReader::_init(_file);
  this->file = _file;
}

void ls::FileReader::_init(ls::File &_file)
{
  if (!_file.exists())
  {
    throw ls::FileNotFoundException{};
  }
}
