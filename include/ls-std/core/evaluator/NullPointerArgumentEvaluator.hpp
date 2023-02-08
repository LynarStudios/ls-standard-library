/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#ifndef LS_STD_NULL_POINTER_ARGUMENT_EVALUATOR_HPP
#define LS_STD_NULL_POINTER_ARGUMENT_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <memory>
#include <string>

namespace ls::std::core
{
  class NullPointerArgumentEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

    explicit NullPointerArgumentEvaluator(const ::std::shared_ptr<void> &_argument);
    explicit NullPointerArgumentEvaluator(const ::std::shared_ptr<void> &_argument, ::std::string _message);
    ~NullPointerArgumentEvaluator() override;

      void evaluate() override;

    private:

      ::std::shared_ptr<void> argument{};
      ::std::string message{};
  };
}

#endif
