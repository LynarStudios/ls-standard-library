/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-04-04
*
* */

#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

using ls::std::core::NullPointerEvaluator;
using ls::std::core::NullPointerException;
using std::make_shared;
using std::move;
using std::shared_ptr;
using std::string;

NullPointerEvaluator::NullPointerEvaluator(const void *_rawArgument)
{
  shared_ptr<void> value{};

  if (_rawArgument != nullptr)
  {
    value = make_shared<int>();
  }

  this->argument = value;
}

NullPointerEvaluator::NullPointerEvaluator(const void *_rawArgument, string _message) : NullPointerEvaluator(_rawArgument)
{
  this->message = ::move(_message);
}

NullPointerEvaluator::NullPointerEvaluator(const shared_ptr<void> &_argument) : argument(_argument)
{}

NullPointerEvaluator::NullPointerEvaluator(const shared_ptr<void> &_argument, string _message) : argument(_argument), message(::move(_message))
{}

NullPointerEvaluator::~NullPointerEvaluator() noexcept = default;

void NullPointerEvaluator::evaluate()
{
  if (this->argument == nullptr)
  {
    if (this->message.empty())
    {
      throw NullPointerException{"reference in use is null!"};
    }
    else
    {
      throw NullPointerException{this->message};
    }
  }
}
