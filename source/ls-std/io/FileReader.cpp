/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-22
 *
 * */

#include <fstream>
#include <ls-std/core/exception/FileOperationException.hpp>
#include <ls-std/io/FileReader.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>

ls::std::io::FileReader::FileReader(ls::std::io::File &_file) : ls::std::core::Class("FileReader"), file(_file)
{
  ls::std::io::FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
}

ls::std::io::FileReader::~FileReader() = default;

ls::std::core::type::byte_field ls::std::io::FileReader::read()
{
  ls::std::core::type::byte *data;
  ::std::ifstream inputStream{this->file.getAbsoluteFilePath(), ::std::ifstream::binary};
  int length = (int) this->file.getSize();
  data = new ls::std::core::type::byte[length];
  inputStream.read(data, length);

  if (inputStream.fail())
  {
    throw ls::std::core::FileOperationException{"operation: read"};
  }

  inputStream.close();
  ls::std::core::type::byte_field readData = ls::std::core::type::byte_field{data, (size_t) this->file.getSize()};
  delete[] data;

  return readData;
}

void ls::std::io::FileReader::reset(ls::std::io::File &_file)
{
  ls::std::io::FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
  this->file = _file;
}
