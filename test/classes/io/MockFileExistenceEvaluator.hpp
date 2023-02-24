/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#ifndef LS_STD_MOCK_FILE_EXISTENCE_EVALUATOR_HPP
#define LS_STD_MOCK_FILE_EXISTENCE_EVALUATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IEvaluator.hpp>

namespace test::io
{
  class MockFileExistenceEvaluator : public ls::std::core::Class, public ls::std::core::interface_type::IEvaluator
  {
    public:

      explicit MockFileExistenceEvaluator(bool _fileExists);
      ~MockFileExistenceEvaluator() noexcept override;

      void evaluate() override;

    private:

      bool fileExists{};
  };
}

#endif
