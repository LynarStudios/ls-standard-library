/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::core::EmptyStringArgumentEvaluator::EmptyStringArgumentEvaluator(::std::string _argument) : argument(::std::move(_argument))
{}

ls::std::core::EmptyStringArgumentEvaluator::EmptyStringArgumentEvaluator(::std::string _argument, ::std::string _message) : argument(::std::move(_argument)), message(::std::move(_message))
{}

ls::std::core::EmptyStringArgumentEvaluator::~EmptyStringArgumentEvaluator() noexcept = default;

void ls::std::core::EmptyStringArgumentEvaluator::evaluate()
{
  if (this->argument.empty())
  {
    if (this->message.empty())
    {
      throw ls::std::core::IllegalArgumentException{"passed argument is empty!"};
    }
    else
    {
      throw ls::std::core::IllegalArgumentException{this->message};
    }
  }
}
