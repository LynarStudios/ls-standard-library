/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::IllegalArgumentException;
using std::move;
using std::string;

EmptyStringArgumentEvaluator::EmptyStringArgumentEvaluator(string _argument) : argument(::move(_argument))
{}

EmptyStringArgumentEvaluator::EmptyStringArgumentEvaluator(string _argument, string _message) : argument(::move(_argument)), message(::move(_message))
{}

EmptyStringArgumentEvaluator::~EmptyStringArgumentEvaluator() noexcept = default;

void EmptyStringArgumentEvaluator::evaluate()
{
  if (this->argument.empty())
  {
    if (this->message.empty())
    {
      throw IllegalArgumentException{"passed argument is empty!"};
    }
    else
    {
      throw IllegalArgumentException{this->message};
    }
  }
}
