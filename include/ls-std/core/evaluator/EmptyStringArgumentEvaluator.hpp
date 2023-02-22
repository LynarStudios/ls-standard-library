/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_EMPTY_STRING_ARGUMENT_EVALUATOR_HPP
#define LS_STD_EMPTY_STRING_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL EmptyStringArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit EmptyStringArgumentEvaluator(::std::string _argument);
      explicit EmptyStringArgumentEvaluator(::std::string _argument, ::std::string _message);
      ~EmptyStringArgumentEvaluator() noexcept override;

      void evaluate() override;

    private:

      ::std::string argument{};
      ::std::string message{};
  };
}

#endif
