/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include "MockFileExistenceEvaluator.hpp"
#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <string>

using ls::std::core::Class;
using ls::std::core::FileNotFoundException;
using std::string;
using test::io::MockFileExistenceEvaluator;

MockFileExistenceEvaluator::MockFileExistenceEvaluator(bool _fileExists) : Class("MockFileExistenceEvaluator"), fileExists(_fileExists)
{}

MockFileExistenceEvaluator::~MockFileExistenceEvaluator() = default;

void MockFileExistenceEvaluator::evaluate()
{
  if (!this->fileExists)
  {
    string message = this->getClassName() + " called - this is just a simulation!";
    throw FileNotFoundException{message};
  }
}
