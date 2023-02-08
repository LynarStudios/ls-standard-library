/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::core::NullPointerArgumentEvaluator::NullPointerArgumentEvaluator(const ::std::shared_ptr<void> &_argument) : argument(_argument)
{}

ls::std::core::NullPointerArgumentEvaluator::NullPointerArgumentEvaluator(const ::std::shared_ptr<void> &_argument, ::std::string _message) : argument(_argument), message(::std::move(_message))
{}

ls::std::core::NullPointerArgumentEvaluator::~NullPointerArgumentEvaluator() = default;

void ls::std::core::NullPointerArgumentEvaluator::evaluate()
{
  if (this->argument == nullptr)
  {
    if (this->message.empty())
    {
      throw ls::std::core::IllegalArgumentException{"passed argument is null!"};
    }
    else
    {
      throw ls::std::core::IllegalArgumentException{this->message};
    }
  }
}
