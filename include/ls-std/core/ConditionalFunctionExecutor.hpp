/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-13
*
* */

#ifndef LS_STD_CONDITIONAL_FUNCTION_EXECUTOR_HPP
#define LS_STD_CONDITIONAL_FUNCTION_EXECUTOR_HPP

#include <functional>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL ConditionalFunctionExecutor
  {
    public:

      explicit ConditionalFunctionExecutor(bool _condition);
      ~ConditionalFunctionExecutor();

      void execute(const ::std::function<void()> &_function);

    private:

      bool condition{};
  };
}

#endif
