/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class KvDocumentTest : public ::testing::Test
  {
    protected:

      KvDocumentTest() = default;
      ~KvDocumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KvDocumentTest, addPair)
  {
    ls_std::KvDocument document{};
    ls_std::KvPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_EQ(1, document.getPairs().size());
  }

  TEST_F(KvDocumentTest, addPairNegative)
  {
    ls_std::KvDocument document{};
    ls_std::KvPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_EQ(1, document.getPairs().size());

    ASSERT_FALSE(document.addPair(pair));
  }

  TEST_F(KvDocumentTest, clear)
  {
    ls_std::KvDocument document{};
    ls_std::KvPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_FALSE(document.getPairs().empty());
    ASSERT_EQ(1, document.getPairs().size());

    document.clear();
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_EQ(0, document.getPairs().size());
  }

  TEST_F(KvDocumentTest, getPairs)
  {
    ls_std::KvDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
  }

  TEST_F(KvDocumentTest, hasPair)
  {
    ls_std::KvDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(ls_std::KvPair{"port", "80"}));
    ASSERT_TRUE(document.hasPair("port"));
  }

  TEST_F(KvDocumentTest, hasPairNegative)
  {
    ls_std::KvDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_FALSE(document.hasPair("port"));
  }

  TEST_F(KvDocumentTest, removePair)
  {
    ls_std::KvDocument document{};
    ASSERT_TRUE(document.addPair(ls_std::KvPair{"port", "80"}));
    ASSERT_TRUE(document.addPair(ls_std::KvPair{"host", "localhost"}));
    ASSERT_TRUE(document.addPair(ls_std::KvPair{"protocol", "TCP"}));
    ASSERT_EQ(3, document.getPairs().size());

    document.removePair("protocol");
    ASSERT_EQ(2, document.getPairs().size());
    ASSERT_TRUE(document.hasPair("port"));
    ASSERT_TRUE(document.hasPair("host"));
  }
}
