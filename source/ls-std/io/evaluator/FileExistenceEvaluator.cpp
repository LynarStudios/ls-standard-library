/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <ls-std/io/File.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>
#include <string>

using ls::std::core::Class;
using ls::std::core::FileNotFoundException;
using ls::std::io::File;
using ls::std::io::FileExistenceEvaluator;
using std::move;
using std::string;

FileExistenceEvaluator::FileExistenceEvaluator(string _filePath) : Class("FileExistenceEvaluator"), filePath(::move(_filePath))
{}

FileExistenceEvaluator::~FileExistenceEvaluator() noexcept = default;

void FileExistenceEvaluator::evaluate()
{
  if (!File{this->filePath}.exists())
  {
    string message = "\"" + this->filePath + "\" does not exist!";
    throw FileNotFoundException{message};
  }
}
