/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2020-09-28
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

    ASSERT_EQ(2020, version.getMajor());
    ASSERT_EQ(2, version.getMinor());
    ASSERT_EQ(13, version.getPatch());
  }

  // other functionality

  TEST_F(VersionTest, getMajor)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(13, version.getMajor());
  }

  TEST_F(VersionTest, getMinor)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(2, version.getMinor());
  }

  TEST_F(VersionTest, getPatch)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(4, version.getPatch());
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

  TEST_F(VersionTest, setMajor)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(13, version.getMajor());

    version.setMajor(14);
    ASSERT_EQ(14, version.getMajor());
  }

  TEST_F(VersionTest, setMinor)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(2, version.getMinor());

    version.setMinor(3);
    ASSERT_EQ(3, version.getMinor());
  }

  TEST_F(VersionTest, setPatch)
  {
    ls_std::Version version {13, 2, 4};
    ASSERT_EQ(4, version.getPatch());

    version.setPatch(5);
    ASSERT_EQ(5, version.getPatch());
  }
}
