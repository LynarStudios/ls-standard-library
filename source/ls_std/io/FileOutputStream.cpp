/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/io/FileOutputStream.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>

ls::std::io::FileOutputStream::FileOutputStream(ls::std::io::File &_file)
    : ls::std::core::Class("FileOutputStream"),
      file(_file)
{
  this->_init();
}

ls::std::io::FileOutputStream::FileOutputStream(ls::std::io::File &_file, bool _append)
    : ls::std::core::Class("FileOutputStream"),
      append(_append),
      file(_file)
{
  this->_init();
}

ls::std::io::FileOutputStream::~FileOutputStream()
{
  this->_close();
}

void ls::std::io::FileOutputStream::close()
{
  this->_close();
}

bool ls::std::io::FileOutputStream::write(const ls::std::core::byte_field &_data)
{
  bool succeeded{};

  if (this->outputStream.is_open())
  {
    if (this->outputStream << _data)
    {
      succeeded = true;
    }
  }
  else
  {
    throw ls::std::core::FileOperationException{};
  }

  return succeeded;
}

void ls::std::io::FileOutputStream::_close()
{
  if (this->outputStream.is_open())
  {
    this->outputStream.close();
  }
}

void ls::std::io::FileOutputStream::_init()
{
  if (!this->file.exists())
  {
    throw ls::std::core::FileNotFoundException{};
  }
  else
  {
    if (this->append)
    {
      this->outputStream.open(this->file.getAbsoluteFilePath(), ::std::ios::out | ::std::ios::app);
    }
    else
    {
      this->outputStream.open(this->file.getAbsoluteFilePath());
    }
  }
}
