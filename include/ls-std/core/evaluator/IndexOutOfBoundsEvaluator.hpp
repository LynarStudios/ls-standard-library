/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_INDEX_OUT_OF_BOUNDS_EVALUATOR_EVALUATOR_HPP
#define LS_STD_INDEX_OUT_OF_BOUNDS_EVALUATOR_EVALUATOR_HPP

#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IndexOutOfBoundsEvaluator : public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit IndexOutOfBoundsEvaluator(size_t _index, size_t _size);
      explicit IndexOutOfBoundsEvaluator(size_t _index, size_t _size, ::std::string _message);
      ~IndexOutOfBoundsEvaluator() noexcept override;

      void evaluate() override;

    private:

      size_t index{};
      ::std::string message{};
      size_t size{};
  };
}

#endif
