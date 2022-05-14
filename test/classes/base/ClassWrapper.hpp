/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_CLASS_MOCK_HPP
#define LS_STD_CLASS_MOCK_HPP

#include <ls_std/ls_std.hpp>
#include <gmock/gmock.h>
// TODO: check if this class is being used with correct include
namespace ls_std_test // TODO: change namespace to core specific namespace
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
