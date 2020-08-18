/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-18
 *
 * */

#include <fstream>
#include "FileReader.hpp"
#include "../exception/FileNotFoundException.hpp"
#include "../exception/FileOperationException.hpp"

ls_std::FileReader::FileReader(File &_file) : Class("FileReader"),
file(_file)
{
  if(!_file.exists()) {
    throw ls_std::FileNotFoundException {};
  }
}

ls_std::byte * ls_std::FileReader::read()
{
  ls_std::byte* data;
  std::ifstream inputStream {this->file.getAbsoluteFilePath(), std::ifstream::binary};
  int length = this->file.getSize();
  data = new ls_std::byte[length];
  inputStream.read(data, length);

  if(!inputStream) {
    throw ls_std::FileOperationException {};
  }

  inputStream.close();
  return data;
}
