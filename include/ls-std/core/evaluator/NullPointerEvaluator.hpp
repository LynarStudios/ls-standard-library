/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_NULL_POINTER_EVALUATOR_HPP
#define LS_STD_NULL_POINTER_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <memory>
#include <string>

namespace ls::std::core
{
  class NullPointerEvaluator : public ls::std::core::interface_type::IEvaluator // TODO: add missing dynamic goal
  {
    public:

      explicit NullPointerEvaluator(const ::std::shared_ptr<void> &_argument);
      explicit NullPointerEvaluator(const ::std::shared_ptr<void> &_argument, ::std::string _message);
      ~NullPointerEvaluator() override;

      void evaluate() override;

    private:

      ::std::shared_ptr<void> argument{};
      ::std::string message{};
  };
}

#endif
