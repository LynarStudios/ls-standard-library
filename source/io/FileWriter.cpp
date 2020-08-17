/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#include <fstream>
#include "FileWriter.hpp"
#include "../exception/FileNotFoundException.hpp"

ls_std::FileWriter::FileWriter(ls_std::File &_file) : Class("FileWriter"),
file(_file)
{
  if(!_file.exists()) {
    throw ls_std::FileNotFoundException {};
  }
}

bool ls_std::FileWriter::write(const ls_std::byte* _data)
{
  std::ofstream outputStream {};
  outputStream.open(this->file.getAbsoluteFilePath());
  bool succeeded {};

  if(outputStream << _data) {
    succeeded = true;
  }

  outputStream.close();
  return succeeded;
}
