/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
*
* */

#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

ls::std::core::NullPointerEvaluator::NullPointerEvaluator(const ::std::shared_ptr<void> &_argument) : argument(_argument)
{}

ls::std::core::NullPointerEvaluator::NullPointerEvaluator(const ::std::shared_ptr<void> &_argument, ::std::string _message) : argument(_argument), message(::std::move(_message))
{}

ls::std::core::NullPointerEvaluator::~NullPointerEvaluator() noexcept = default;

void ls::std::core::NullPointerEvaluator::evaluate()
{
  if (this->argument == nullptr)
  {
    if (this->message.empty())
    {
      throw ls::std::core::NullPointerException{"reference in use is null!"};
    }
    else
    {
      throw ls::std::core::NullPointerException{this->message};
    }
  }
}
