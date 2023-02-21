/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#ifndef LS_STD_FILE_EXISTENCE_EVALUATOR_HPP
#define LS_STD_FILE_EXISTENCE_EVALUATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IEvaluator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL FileExistenceEvaluator : public ls::std::core::Class, public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit FileExistenceEvaluator(::std::string _filePath);
      ~FileExistenceEvaluator() override;

      void evaluate() override;

    private:

      ::std::string filePath{};
  };
}

#endif
