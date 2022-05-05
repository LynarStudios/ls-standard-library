/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class VersionTest : public ::testing::Test
  {
    protected:

      VersionTest() = default;
      ~VersionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // implementation

  TEST_F(VersionTest, marshal)
  {
    ls::Version version{2020, 2, 0};
    ASSERT_STREQ("2020.2.0", version.marshal().c_str());
  }

  TEST_F(VersionTest, unmarshal)
  {
    ls::Version version{0, 0, 0};
    version.unmarshal("2020.2.13");

    ASSERT_EQ(2020, version.getMajorVersion());
    ASSERT_EQ(2, version.getMinorVersion());
    ASSERT_EQ(13, version.getPatchVersion());
  }

  // other functionality

  TEST_F(VersionTest, getMajorVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());
  }

  TEST_F(VersionTest, getMinorVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());
  }

  TEST_F(VersionTest, getPatchVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());
  }

  TEST_F(VersionTest, isValid)
  {
    ASSERT_TRUE(ls::Version::isValid("2020.1.2"));
    ASSERT_TRUE(ls::Version::isValid("2.5.1"));
  }

  TEST_F(VersionTest, isValid_emptyString)
  {
    ASSERT_FALSE(ls::Version::isValid(""));
  }

  TEST_F(VersionTest, isValid_noValidVersionString)
  {
    ASSERT_FALSE(ls::Version::isValid("v2020.1.2"));
    ASSERT_FALSE(ls::Version::isValid("2.5"));
    ASSERT_FALSE(ls::Version::isValid("2020"));
    ASSERT_FALSE(ls::Version::isValid("blaaaa"));
  }

  TEST_F(VersionTest, setMajorVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());

    version.setMajorVersion(14);
    ASSERT_EQ(14, version.getMajorVersion());
  }

  TEST_F(VersionTest, setMinorVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());

    version.setMinorVersion(3);
    ASSERT_EQ(3, version.getMinorVersion());
  }

  TEST_F(VersionTest, setPatchVersion)
  {
    ls::Version version{13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());

    version.setPatchVersion(5);
    ASSERT_EQ(5, version.getPatchVersion());
  }
}
