/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-23
 *
 * */

#include <fstream>
#include <ls-std/core/exception/FileOperationException.hpp>
#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>

using ls::std::core::Class;
using ls::std::core::FileOperationException;
using ls::std::core::type::byte_field;
using ls::std::core::type::byte_type;
using ls::std::io::File;
using ls::std::io::FileExistenceEvaluator;
using ls::std::io::FileReader;
using std::ifstream;

FileReader::FileReader(File &_file) : Class("FileReader"), file(_file)
{
  FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
}

FileReader::~FileReader() noexcept = default;

byte_field FileReader::read()
{
  byte_type *data;
  ifstream inputStream{this->file.getAbsoluteFilePath(), ifstream::binary};
  int length = (int) this->file.getSize();
  data = new byte_type[length];
  inputStream.read(data, length);

  if (inputStream.fail())
  {
    throw FileOperationException{"operation: read"};
  }

  inputStream.close();
  byte_field readData = byte_field{data, (size_t) this->file.getSize()};
  delete[] data;

  return readData;
}

void FileReader::reset(File &_file)
{
  FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
  this->file = _file;
}
