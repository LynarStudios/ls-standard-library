/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#ifndef LS_STD_I_EVALUATOR_HPP
#define LS_STD_I_EVALUATOR_HPP

#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IEvaluator
  {
    public:

      IEvaluator();
      virtual ~IEvaluator();

      virtual void evaluate() = 0;
  };
}

#endif
