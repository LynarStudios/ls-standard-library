/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include "MockFileExistenceEvaluator.hpp"
#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <string>

test::io::MockFileExistenceEvaluator::MockFileExistenceEvaluator(bool _fileExists) : ls::std::core::Class("MockFileExistenceEvaluator"), fileExists(_fileExists)
{}

test::io::MockFileExistenceEvaluator::~MockFileExistenceEvaluator() = default;

void test::io::MockFileExistenceEvaluator::evaluate()
{
  if (!this->fileExists)
  {
    ::std::string message = this->getClassName() + " called - this is just a simulation!";
    throw ls::std::core::FileNotFoundException{message};
  }
}
