/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class XMLDeclarationTest : public ::testing::Test
  {
    protected:

      XMLDeclarationTest() = default;
      ~XMLDeclarationTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XMLDeclarationTest, getEncoding)
  {
    ls_std::XMLDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getEncoding().empty());
  }

  TEST_F(XMLDeclarationTest, getStandalone)
  {
    ls_std::XMLDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getStandalone().empty());
  }

  TEST_F(XMLDeclarationTest, getVersion)
  {
    ls_std::XMLDeclaration declaration{"1.0"};
    ASSERT_FALSE(declaration.getVersion().empty());
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());
  }

  TEST_F(XMLDeclarationTest, setEncoding)
  {
    ls_std::XMLDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getEncoding().empty());

    declaration.setEncoding("iso-8859-1");
    ASSERT_STREQ("iso-8859-1", declaration.getEncoding().c_str());
  }

  TEST_F(XMLDeclarationTest, setStandalone)
  {
    ls_std::XMLDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getStandalone().empty());

    declaration.setStandalone("no");
    ASSERT_STREQ("no", declaration.getStandalone().c_str());
  }

  TEST_F(XMLDeclarationTest, setVersion)
  {
    ls_std::XMLDeclaration declaration{"1.0"};

    ASSERT_FALSE(declaration.getVersion().empty());
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());

    declaration.setVersion("1.1");
    ASSERT_STREQ("1.1", declaration.getVersion().c_str());
  }

  TEST_F(XMLDeclarationTest, toXML)
  {
    ls_std::XMLDeclaration declaration{"1.0"};
    ASSERT_STREQ(R"(<?xml version="1.0" ?>)", declaration.toXML().c_str());

    declaration.setStandalone("yes");
    ASSERT_STREQ(R"(<?xml version="1.0" standalone="yes" ?>)", declaration.toXML().c_str());

    declaration.setEncoding("UTF-8");
    ASSERT_STREQ(R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>)", declaration.toXML().c_str());
  }
}
