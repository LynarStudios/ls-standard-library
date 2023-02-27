/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/FileOperationException.hpp>
#include <ls-std/io/FileOutputStream.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>

using ls::std::core::Class;
using ls::std::core::FileOperationException;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileExistenceEvaluator;
using ls::std::io::FileOutputStream;
using std::ios;

FileOutputStream::FileOutputStream(File &_file) : Class("FileOutputStream"), file(_file)
{
  this->_init();
}

FileOutputStream::FileOutputStream(File &_file, bool _append) : Class("FileOutputStream"), append(_append), file(_file)
{
  this->_init();
}

FileOutputStream::~FileOutputStream() noexcept
{
  this->_close();
}

void FileOutputStream::close()
{
  this->_close();
}

bool FileOutputStream::write(const byte_field &_data)
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
    throw FileOperationException{"operation: write"};
  }

  return succeeded;
}

void FileOutputStream::_close()
{
  if (this->outputStream.is_open())
  {
    this->outputStream.close();
  }
}

void FileOutputStream::_init()
{
  FileExistenceEvaluator{this->file.getAbsoluteFilePath()}.evaluate();

  if (this->append)
  {
    this->outputStream.open(this->file.getAbsoluteFilePath(), ios::out | ios::app);
  }
  else
  {
    this->outputStream.open(this->file.getAbsoluteFilePath());
  }
}
