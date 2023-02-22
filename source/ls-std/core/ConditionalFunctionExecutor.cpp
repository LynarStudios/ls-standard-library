/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-21
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>

ls::std::core::ConditionalFunctionExecutor::ConditionalFunctionExecutor(bool _condition) : condition(_condition)
{}

ls::std::core::ConditionalFunctionExecutor::~ConditionalFunctionExecutor() = default;

void ls::std::core::ConditionalFunctionExecutor::execute(const ::std::function<void()> &_function) const
{
  if (this->condition)
  {
    _function();
  }
}
