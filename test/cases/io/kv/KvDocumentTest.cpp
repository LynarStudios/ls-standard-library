/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_io.hpp>

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
    ls::std::io::KvDocument document{};
    ls::std::io::KvPair pair{"port", "13088"};

    ASSERT_TRUE(document.addPair(pair));
    ASSERT_EQ(1, document.getPairs().size());
  }

  TEST_F(KvDocumentTest, addPair_retry_to_add_pair)
  {
    ls::std::io::KvDocument document{};
    ls::std::io::KvPair pair{"port", "13088"};

    ASSERT_TRUE(document.addPair(pair));
    ASSERT_FALSE(document.addPair(pair));
  }

  TEST_F(KvDocumentTest, clear)
  {
    // preparation

    ls::std::io::KvDocument document{};
    ls::std::io::KvPair pair{"port", "13088"};
    document.addPair(pair);

    // check

    document.clear();
    ASSERT_TRUE(document.getPairs().empty());
    ASSERT_EQ(0, document.getPairs().size());
  }

  TEST_F(KvDocumentTest, getPairs)
  {
    ls::std::io::KvDocument document{};
    ASSERT_TRUE(document.getPairs().empty());
  }

  TEST_F(KvDocumentTest, hasPair)
  {
    ls::std::io::KvDocument document{};
    document.addPair(ls::std::io::KvPair{"port", "80"});

    ASSERT_TRUE(document.hasPair("port"));
  }

  TEST_F(KvDocumentTest, hasPair_no_pairs_available)
  {
    ls::std::io::KvDocument document{};
    ASSERT_FALSE(document.hasPair("port"));
  }

  TEST_F(KvDocumentTest, removePair)
  {
    // preparation

    ls::std::io::KvDocument document{};
    document.addPair(ls::std::io::KvPair{"port", "80"});
    document.addPair(ls::std::io::KvPair{"host", "localhost"});
    document.addPair(ls::std::io::KvPair{"protocol", "TCP"});

    // remove pair and check

    ASSERT_TRUE(document.removePair("protocol"));
    ASSERT_EQ(2, document.getPairs().size());
    ASSERT_TRUE(document.hasPair("port"));
    ASSERT_TRUE(document.hasPair("host"));
  }

  TEST_F(KvDocumentTest, removePair_no_pair_available)
  {
    ls::std::io::KvDocument document{};
    ASSERT_FALSE(document.removePair("port"));
  }
}
