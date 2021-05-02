/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <ls_std/ls_std.hpp>
#include <gmock/gmock.h>

namespace ls_std_test
{
  class ClassWrapper : public ls_std::Class
  {
    public:

      ClassWrapper() : ls_std::Class("ClassWrapper") {};
      MOCK_METHOD0(Die, void());
      ~ClassWrapper() override { Die(); }
  };
}

#endif
