/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#ifndef LS_STD_EMPTY_STRING_ARGUMENT_EVALUATOR_HPP
#define LS_STD_EMPTY_STRING_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <string>

namespace ls::std::core
{
  class EmptyStringArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit EmptyStringArgumentEvaluator(::std::string _argument);
      EmptyStringArgumentEvaluator(::std::string _argument, ::std::string _message);
      ~EmptyStringArgumentEvaluator() override;

      void evaluate() override;

    private:

      ::std::string argument{};
      ::std::string message{};
  };
}

#endif
