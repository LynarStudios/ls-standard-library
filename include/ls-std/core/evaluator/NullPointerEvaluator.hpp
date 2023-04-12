/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-04-04
*
* */

#ifndef LS_STD_NULL_POINTER_EVALUATOR_HPP
#define LS_STD_NULL_POINTER_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL NullPointerEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit NullPointerEvaluator(const void *_rawArgument);
      explicit NullPointerEvaluator(const void *_rawArgument, ::std::string _message);
      explicit NullPointerEvaluator(const ::std::shared_ptr<void> &_argument);
      explicit NullPointerEvaluator(const ::std::shared_ptr<void> &_argument, ::std::string _message);
      ~NullPointerEvaluator() noexcept override;

      void evaluate() override;

    private:

      ::std::shared_ptr<void> argument{};
      ::std::string message{};
  };
}

#endif
