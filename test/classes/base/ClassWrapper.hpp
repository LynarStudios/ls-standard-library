/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2022-05-16
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <ls_std/ls_std_core.hpp>
#include <gmock/gmock.h>

namespace ls_std_core_test
{
  class ClassWrapper : public ls::std::core::Class
  {
    public:

      ClassWrapper() : ls::std::core::Class("ClassWrapper") {};
      MOCK_METHOD0(Die, void());
      ~ClassWrapper() override { Die(); }
  };
}

#endif
