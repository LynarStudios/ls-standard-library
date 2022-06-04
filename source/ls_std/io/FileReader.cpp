/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-12
 *
 * */

#include <fstream>
#include <ls_std/io/FileReader.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>

ls::std::io::FileReader::FileReader(ls::std::io::File &_file)
    : ls::std::core::Class("FileReader"),
      file(_file)
{
  ls::std::io::FileReader::_init(_file);
}

ls::std::core::type::byte_field ls::std::io::FileReader::read()
{
  ls::std::core::type::byte *data;
  ::std::ifstream inputStream{this->file.getAbsoluteFilePath(), ::std::ifstream::binary};
  int length = (int) this->file.getSize();
  data = new ls::std::core::type::byte[length];
  inputStream.read(data, length);

  if (inputStream.fail())
  {
    throw ls::std::core::FileOperationException{};
  }

  inputStream.close();
  ls::std::core::type::byte_field readData = ls::std::core::type::byte_field{data, (size_t) this->file.getSize()};
  delete[] data;

  return readData;
}

void ls::std::io::FileReader::reset(ls::std::io::File &_file)
{
  ls::std::io::FileReader::_init(_file);
  this->file = _file;
}

void ls::std::io::FileReader::_init(ls::std::io::File &_file)
{
  if (!_file.exists())
  {
    throw ls::std::core::FileNotFoundException{};
  }
}
