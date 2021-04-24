/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std_test.hpp>

namespace
{
  class SerializableFactoryTest : public ::testing::Test
  {
    protected:

      SerializableFactoryTest() = default;
      ~SerializableFactoryTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableFactoryTest, addFactory)
  {
    std::shared_ptr<ls_std_test::SerializableTestFactory> serializableTestFactory = std::make_shared<ls_std_test::SerializableTestFactory>();
    ls_std::SerializableFactory serializableFactory{};

    ASSERT_TRUE(serializableFactory.addFactory({"TestClass", serializableTestFactory}));
  }

  TEST_F(SerializableFactoryTest, addFactory_emptyKey)
  {
    std::shared_ptr<ls_std_test::SerializableTestFactory> serializableTestFactory = std::make_shared<ls_std_test::SerializableTestFactory>();
    ls_std::SerializableFactory serializableFactory{};

    EXPECT_THROW({
                   try
                   {
                     serializableFactory.addFactory({"", serializableTestFactory});
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     EXPECT_STREQ("IllegalArgumentException thrown - passed argument is not valid!", _exception.what());
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(SerializableFactoryTest, addFactory_nullPointerValueForFactory)
  {
    std::shared_ptr<ls_std_test::SerializableTestFactory> serializableTestFactory{};
    ls_std::SerializableFactory serializableFactory{};

    EXPECT_THROW({
                   try
                   {
                     serializableFactory.addFactory({"TestClass", serializableTestFactory});
                   }
                   catch (const ls_std::NullPointerException &_exception)
                   {
                     EXPECT_STREQ("NullPointerException thrown - reference is null!", _exception.what());
                     throw;
                   }
                 }, ls_std::NullPointerException);
  }

  TEST_F(SerializableFactoryTest, addFactory_dublicatedElement)
  {
    std::shared_ptr<ls_std_test::SerializableTestFactory> serializableTestFactory = std::make_shared<ls_std_test::SerializableTestFactory>();
    ls_std::SerializableFactory serializableFactory{};

    ASSERT_TRUE(serializableFactory.addFactory({"TestClass", serializableTestFactory}));
    ASSERT_FALSE(serializableFactory.addFactory({"TestClass", serializableTestFactory}));
  }

  TEST_F(SerializableFactoryTest, build)
  {
    ls_std::SerializableFactory serializableFactory{};
    std::shared_ptr<ls_std::Class> serializable = serializableFactory.build(ls_std::Boolean{}.getClassName());

    ASSERT_TRUE(serializable != nullptr);
    ASSERT_STREQ(ls_std::Boolean{}.getClassName().c_str(), serializable->getClassName().c_str());
  }

  TEST_F(SerializableFactoryTest, build_factoryNotAvailable)
  {
    ls_std::SerializableFactory serializableFactory{};
    std::shared_ptr<ls_std::Class> serializable = serializableFactory.build(ls_std_test::GossipNewsAgency{}.getClassName());

    ASSERT_FALSE(serializable != nullptr);
  }

  TEST_F(SerializableFactoryTest, clear)
  {
    ls_std::SerializableFactory serializableFactory{};
    ASSERT_TRUE(serializableFactory.clear());
  }

  TEST_F(SerializableFactoryTest, hasFactory)
  {
    ls_std::SerializableFactory serializableFactory{};
    ASSERT_TRUE(serializableFactory.hasFactory(ls_std::Boolean{}.getClassName()));
  }

  TEST_F(SerializableFactoryTest, hasFactory_factoryNotAvailable)
  {
    ls_std::SerializableFactory serializableFactory{};
    ASSERT_FALSE(serializableFactory.hasFactory(ls_std_test::GossipNewsAgency{}.getClassName()));
  }

  TEST_F(SerializableFactoryTest, removeFactory)
  {
    ls_std::SerializableFactory serializableFactory{};
    ASSERT_TRUE(serializableFactory.removeFactory(ls_std::Boolean{}.getClassName()));
  }

  TEST_F(SerializableFactoryTest, removeFactory_factoryNotAvailable)
  {
    ls_std::SerializableFactory serializableFactory{};
    ASSERT_FALSE(serializableFactory.removeFactory(ls_std_test::GossipNewsAgency{}.getClassName()));
  }
}
