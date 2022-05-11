/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_TEST_DATA_FACTORY_HPP
#define LS_STD_TEST_DATA_FACTORY_HPP

#include <ls_std/ls_std.hpp>

namespace ls_std_test
{
  class TestDataFactory
  {
    public:

      TestDataFactory() = default;
      ~TestDataFactory() = default;

      static ls::StateMachine createStateMachine();
      static std::shared_ptr<ls::std::io::XmlNode> createXmlContent();
  };
}

#endif
