/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>

using ls::std::core::Version;
using testing::Test;

namespace
{
  class VersionTest : public Test
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
    Version version{2020, 2, 0};
    ASSERT_STREQ("2020.2.0", version.marshal().c_str());
  }

  TEST_F(VersionTest, unmarshal)
  {
    Version version{0, 0, 0};
    version.unmarshal("2020.2.13");

    ASSERT_EQ(2020, version.getMajorVersion());
    ASSERT_EQ(2, version.getMinorVersion());
    ASSERT_EQ(13, version.getPatchVersion());
  }

  // other functionality

  TEST_F(VersionTest, getMajorVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());
  }

  TEST_F(VersionTest, getMinorVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());
  }

  TEST_F(VersionTest, getPatchVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());
  }

  TEST_F(VersionTest, isValid)
  {
    ASSERT_TRUE(Version::isValid("2020.1.2"));
    ASSERT_TRUE(Version::isValid("2.5.1"));
  }

  TEST_F(VersionTest, isValid_emptyString)
  {
    ASSERT_FALSE(Version::isValid(""));
  }

  TEST_F(VersionTest, isValid_noValidVersionString)
  {
    ASSERT_FALSE(Version::isValid("v2020.1.2"));
    ASSERT_FALSE(Version::isValid("2.5"));
    ASSERT_FALSE(Version::isValid("2020"));
    ASSERT_FALSE(Version::isValid("blaaaa"));
  }

  TEST_F(VersionTest, setMajorVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());

    version.setMajorVersion(14);
    ASSERT_EQ(14, version.getMajorVersion());
  }

  TEST_F(VersionTest, setMinorVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());

    version.setMinorVersion(3);
    ASSERT_EQ(3, version.getMinorVersion());
  }

  TEST_F(VersionTest, setPatchVersion)
  {
    Version version{13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());

    version.setPatchVersion(5);
    ASSERT_EQ(5, version.getPatchVersion());
  }
}
