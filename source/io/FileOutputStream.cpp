/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#include "FileOutputStream.hpp"
#include "../exception/FileNotFoundException.hpp"
#include "../exception/FileOperationException.hpp"

ls_std::FileOutputStream::FileOutputStream(File &_file) : Class("FileOutputStream"),
file(_file)
{
  if(!_file.exists()) {
    throw ls_std::FileNotFoundException {};
  } else {
    this->outputStream.open(_file.getAbsoluteFilePath());
  }
}

ls_std::FileOutputStream::~FileOutputStream()
{
  this->_close();
}

void ls_std::FileOutputStream::close()
{
  this->_close();
}

bool ls_std::FileOutputStream::write(const ls_std::byte *_data)
{
  bool succeeded {};

  if(this->outputStream.is_open()) {
    if (this->outputStream << _data) {
      succeeded = true;
    }
  } else {
    throw ls_std::FileOperationException {};
  }

  return succeeded;
}

void ls_std::FileOutputStream::_close()
{
  if(this->outputStream.is_open()) {
    this->outputStream.close();
  }
}