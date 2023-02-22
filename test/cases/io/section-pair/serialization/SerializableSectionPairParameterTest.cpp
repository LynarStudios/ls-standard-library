/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-17
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SerializableSectionPairParameterTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairParameterTest() = default;
      ~SerializableSectionPairParameterTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableSectionPairParameterTest, getNewLine)
  {
    ASSERT_STREQ(NewLine::get().c_str(), SerializableSectionPairParameter{}.getNewLine().c_str());
  }

  TEST_F(SerializableSectionPairParameterTest, getValue)
  {
    ASSERT_TRUE(SerializableSectionPairParameter{}.getValue() == nullptr);
  }

  TEST_F(SerializableSectionPairParameterTest, setNewLine)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setNewLine("\r\n");

    ASSERT_STREQ("\r\n", parameter.getNewLine().c_str());
  }

  TEST_F(SerializableSectionPairParameterTest, setValue)
  {
    SerializableSectionPairParameter parameter{};
    parameter.setValue(make_shared<SectionPairRowSingleValue>("blue"));

    ASSERT_TRUE(parameter.getValue() != nullptr);
  }
}
