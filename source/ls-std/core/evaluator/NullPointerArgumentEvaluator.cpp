/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::NullPointerArgumentEvaluator;
using std::move;
using std::shared_ptr;
using std::string;

NullPointerArgumentEvaluator::NullPointerArgumentEvaluator(const shared_ptr<void> &_argument) : argument(_argument)
{}

NullPointerArgumentEvaluator::NullPointerArgumentEvaluator(const shared_ptr<void> &_argument, string _message) : argument(_argument), message(::move(_message))
{}

NullPointerArgumentEvaluator::~NullPointerArgumentEvaluator() noexcept = default;

void NullPointerArgumentEvaluator::evaluate()
{
  if (this->argument == nullptr)
  {
    if (this->message.empty())
    {
      throw IllegalArgumentException{"passed argument is null!"};
    }
    else
    {
      throw IllegalArgumentException{this->message};
    }
  }
}
