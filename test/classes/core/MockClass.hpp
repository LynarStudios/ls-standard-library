/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2022-12-16
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <ls_std/ls_std_core.hpp>
#include <gmock/gmock.h>

namespace ls_std_core_test
{
  class MockClass : public ls::std::core::Class
  {
    public:

      MockClass() : ls::std::core::Class("ClassWrapper") {};
      MOCK_METHOD0(Die, void());
      ~MockClass() override { Die(); }
  };
}

#endif
