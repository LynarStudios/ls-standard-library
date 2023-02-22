/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-22
 *
 * */

#include <fstream>
#include <ls-std/io/FileWriter.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>

ls::std::io::FileWriter::FileWriter(ls::std::io::File &_file) : ls::std::core::Class("FileWriter"), file(_file)
{
  ls::std::io::FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
}

ls::std::io::FileWriter::~FileWriter() noexcept = default;

void ls::std::io::FileWriter::reset(ls::std::io::File &_file)
{
  ls::std::io::FileExistenceEvaluator{_file.getAbsoluteFilePath()}.evaluate();
  this->file = _file;
}

bool ls::std::io::FileWriter::write(const ls::std::core::type::byte_field &_data)
{
  ::std::ofstream outputStream{};
  outputStream.open(this->file.getAbsoluteFilePath());
  outputStream << _data;

  return !outputStream.fail();
}
