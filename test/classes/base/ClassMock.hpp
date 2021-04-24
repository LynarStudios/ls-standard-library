/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <ls_std/ls_std.hpp>
#include <gmock/gmock.h>

namespace ls_std_test
{
  class ClassMock : public ls_std::Class
  {
    public:

      ClassMock() : ls_std::Class("ClassMock") {};
      MOCK_METHOD0(Die, void());
      ~ClassMock() override { Die(); }
  };
}

#endif
