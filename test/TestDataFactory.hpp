/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2020-09-26
 *
 * */

#ifndef LS_STD_TEST_DATA_FACTORY_HPP
#define LS_STD_TEST_DATA_FACTORY_HPP

#include "../source/logic/StateMachine.hpp"
#include "../source/io/xml/XMLNode.hpp"

namespace ls_std_test {
  class TestDataFactory {
    public:

      TestDataFactory() = default;
      ~TestDataFactory() = default;

      static ls_std::StateMachine createStateMachine();
      static std::shared_ptr<ls_std::XMLNode> createXMLContent();
  };
}

#endif
