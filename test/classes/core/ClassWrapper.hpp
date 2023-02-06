/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <gmock/gmock.h>
#include <ls-std/ls-std-core.hpp>

namespace test::core
{
  class ClassWrapper : public ls::std::core::Class
  {
    public:

      ClassWrapper();
      ~ClassWrapper() override;

      MOCK_METHOD0(Die, void());
  };
}

#endif