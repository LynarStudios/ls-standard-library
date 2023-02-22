/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::testing;

namespace
{
  class XmlDeclarationTest : public Test
  {
    protected:

      XmlDeclarationTest() = default;
      ~XmlDeclarationTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(XmlDeclarationTest, constructor_empty_version)
  {
    EXPECT_THROW(
        {
          try
          {
            XmlDeclaration declaration{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, getEncoding)
  {
    XmlDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getEncoding().empty());
  }

  TEST_F(XmlDeclarationTest, getStandalone)
  {
    XmlDeclaration declaration{"1.0"};
    ASSERT_TRUE(declaration.getStandalone().empty());
  }

  TEST_F(XmlDeclarationTest, getVersion)
  {
    XmlDeclaration declaration{"1.0"};
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());
  }

  TEST_F(XmlDeclarationTest, setEncoding)
  {
    XmlDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getEncoding().empty());

    declaration.setEncoding("iso-8859-1");
    ASSERT_STREQ("iso-8859-1", declaration.getEncoding().c_str());
  }

  TEST_F(XmlDeclarationTest, setEncoding_empty_encoding)
  {
    XmlDeclaration declaration{"1.0"};

    EXPECT_THROW(
        {
          try
          {
            declaration.setEncoding("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, setStandalone)
  {
    XmlDeclaration declaration{"1.0"};

    ASSERT_TRUE(declaration.getStandalone().empty());

    declaration.setStandalone("no");
    ASSERT_STREQ("no", declaration.getStandalone().c_str());
  }

  TEST_F(XmlDeclarationTest, setStandalone_empty_standalone)
  {
    XmlDeclaration declaration{"1.0"};

    EXPECT_THROW(
        {
          try
          {
            declaration.setStandalone("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, setVersion)
  {
    XmlDeclaration declaration{"1.0"};

    ASSERT_FALSE(declaration.getVersion().empty());
    ASSERT_STREQ("1.0", declaration.getVersion().c_str());

    declaration.setVersion("1.1");
    ASSERT_STREQ("1.1", declaration.getVersion().c_str());
  }

  TEST_F(XmlDeclarationTest, setVersion_empty_version)
  {
    XmlDeclaration declaration{"1.0"};

    EXPECT_THROW(
        {
          try
          {
            declaration.setVersion("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(XmlDeclarationTest, toXml)
  {
    XmlDeclaration declaration{"1.0"};
    ASSERT_STREQ(R"(<?xml version="1.0" ?>)", declaration.toXml().c_str());

    declaration.setStandalone("yes");
    ASSERT_STREQ(R"(<?xml version="1.0" standalone="yes" ?>)", declaration.toXml().c_str());

    declaration.setEncoding("UTF-8");
    ASSERT_STREQ(R"(<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>)", declaration.toXml().c_str());
  }
}
