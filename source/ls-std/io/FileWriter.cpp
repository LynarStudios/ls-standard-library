/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-23
 *
 * */

#include <fstream>
#include <ls-std/io/FileWriter.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>

using ls::std::core::Class;
using ls::std::core::type::byte_field;
using ls::std::io::File;
using ls::std::io::FileExistenceEvaluator;
using ls::std::io::FileWriter;
using ::std::ofstream;

FileWriter::FileWriter(File &_file) : Class("FileWriter"), file(_file)
{
  FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
}

FileWriter::~FileWriter() noexcept = default;

void FileWriter::reset(File &_file)
{
  FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
  this->file = _file;
}

bool FileWriter::write(const byte_field &_data)
{
  ofstream outputStream{};
  outputStream.open(this->file.getAbsoluteFilePath());
  outputStream << _data;

  return !outputStream.fail();
}
