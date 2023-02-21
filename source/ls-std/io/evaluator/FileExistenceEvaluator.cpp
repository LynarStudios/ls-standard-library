/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <ls-std/io/File.hpp>
#include <ls-std/io/evaluator/FileExistenceEvaluator.hpp>
#include <string>

ls::std::io::FileExistenceEvaluator::FileExistenceEvaluator(::std::string _filePath) : ls::std::core::Class("FileExistenceEvaluator"), filePath(::std::move(_filePath))
{}

ls::std::io::FileExistenceEvaluator::~FileExistenceEvaluator() = default;

void ls::std::io::FileExistenceEvaluator::evaluate()
{
  if (!ls::std::io::File{this->filePath}.exists())
  {
    ::std::string message = "\"" + this->filePath + "\" does not exist!";
    throw ls::std::core::FileNotFoundException{message};
  }
}
