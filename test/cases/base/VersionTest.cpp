/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2020-09-29
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/base/Version.hpp"

namespace {
  class VersionTest : public ::testing::Test {
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
    ls_std::Version version {2020, 2, 0};
    ASSERT_STREQ("2020.2.0", version.marshal().c_str());
  }

  TEST_F(VersionTest, unmarshal)
  {
    ls_std::Version version {0, 0, 0};
    version.unmarshal("2020.2.13");

    ASSERT_EQ(2020, version.getMajorVersion());
    ASSERT_EQ(2, version.getMinorVersion());
    ASSERT_EQ(13, version.getPatchVersion());
  }

  // other functionality

  TEST_F(VersionTest, getMajorVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());
  }

  TEST_F(VersionTest, getMinorVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());
  }

  TEST_F(VersionTest, getPatchVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());
  }

  TEST_F(VersionTest, isValid)
  {
    ASSERT_TRUE(ls_std::Version::isValid("2020.1.2"));
    ASSERT_TRUE(ls_std::Version::isValid("2.5.1"));
  }

  TEST_F(VersionTest, isValidNegative)
  {
    ASSERT_FALSE(ls_std::Version::isValid("v2020.1.2"));
    ASSERT_FALSE(ls_std::Version::isValid("2.5"));
    ASSERT_FALSE(ls_std::Version::isValid("2020"));
    ASSERT_FALSE(ls_std::Version::isValid("blaaaa"));
  }

  TEST_F(VersionTest, setMajorVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(13, version.getMajorVersion());

    version.setMajorVersion(14);
    ASSERT_EQ(14, version.getMajorVersion());
  }

  TEST_F(VersionTest, setMinorVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(2, version.getMinorVersion());

    version.setMinorVersion(3);
    ASSERT_EQ(3, version.getMinorVersion());
  }

  TEST_F(VersionTest, setPatchVersion)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(4, version.getPatchVersion());

    version.setPatchVersion(5);
    ASSERT_EQ(5, version.getPatchVersion());
  }
}
