/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-23
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>

using ls::std::core::ConditionalFunctionExecutor;
using std::function;

ConditionalFunctionExecutor::ConditionalFunctionExecutor(bool _condition) : condition(_condition)
{}

ConditionalFunctionExecutor::~ConditionalFunctionExecutor() = default;

void ConditionalFunctionExecutor::execute(const function<void()> &_function) const
{
  if (this->condition)
  {
    _function();
  }
}
