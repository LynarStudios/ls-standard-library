/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class KVDocumentTest : public ::testing::Test
  {
    protected:

      KVDocumentTest() = default;
      ~KVDocumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(KVDocumentTest, addPair)
  {
    ls_std::KVDocument document{};
    ls_std::KVPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_EQ(1, document.getPairs().size());
  }

  TEST_F(KVDocumentTest, addPairNegative)
  {
    ls_std::KVDocument document{};
    ls_std::KVPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_EQ(1, document.getPairs().size());

    ASSERT_FALSE(document.addPair(pair));
  }

  TEST_F(KVDocumentTest, clear)
  {
    ls_std::KVDocument document{};
    ls_std::KVPair pair{"port", "13088"};

    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(pair));
    ASSERT_FALSE(document.getPairs().empty());
    ASSERT_EQ(1, document.getPairs().size());

    document.clear();
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_EQ(0, document.getPairs().size());
  }

  TEST_F(KVDocumentTest, getPairs)
  {
    ls_std::KVDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
  }

  TEST_F(KVDocumentTest, hasPair)
  {
    ls_std::KVDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_TRUE(document.addPair(ls_std::KVPair{"port", "80"}));
    ASSERT_TRUE(document.hasPair("port"));
  }

  TEST_F(KVDocumentTest, hasPairNegative)
  {
    ls_std::KVDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_FALSE(document.hasPair("port"));
  }

  TEST_F(KVDocumentTest, removePair)
  {
    ls_std::KVDocument document{};
    ASSERT_TRUE(document.addPair(ls_std::KVPair{"port", "80"}));
    ASSERT_TRUE(document.addPair(ls_std::KVPair{"host", "localhost"}));
    ASSERT_TRUE(document.addPair(ls_std::KVPair{"protocol", "TCP"}));
    ASSERT_EQ(3, document.getPairs().size());

    document.removePair("protocol");
    ASSERT_EQ(2, document.getPairs().size());
    ASSERT_TRUE(document.hasPair("port"));
    ASSERT_TRUE(document.hasPair("host"));
  }
}
