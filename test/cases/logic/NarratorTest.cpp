/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-05
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <classes/observer/TestDataMercedesCar.hpp>

namespace
{
  class NarratorTest : public ::testing::Test
  {
    protected:

      NarratorTest() = default;
      ~NarratorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes1{};
      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes2{};
      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes3{};

      void createCars()
      {
        this->mercedes1 = std::make_shared<ls_std_test::TestDataMercedesCar>();
        this->mercedes1->setColor("pink");
        this->mercedes2 = std::make_shared<ls_std_test::TestDataMercedesCar>();
        this->mercedes2->setColor("blue");
        this->mercedes3 = std::make_shared<ls_std_test::TestDataMercedesCar>();
        this->mercedes3->setColor("red");
      }
  };

  TEST_F(NarratorTest, addListener)
  {
    this->createCars();
    ls::Narrator paintingMachine{};

    ASSERT_TRUE(paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1)));
    ASSERT_TRUE(paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes2)));
    ASSERT_TRUE(paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes3)));
  }

  TEST_F(NarratorTest, addListener_listener_already_exists)
  {
    this->createCars();
    ls::Narrator paintingMachine{};

    ASSERT_TRUE(paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1)));
    ASSERT_FALSE(paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1)));
  }

  TEST_F(NarratorTest, addListener_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Narrator paintingMachine{};
                     paintingMachine.addListener(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(NarratorTest, clear)
  {
    this->createCars();
    ls::Narrator paintingMachine{};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes3));

    ASSERT_FALSE(paintingMachine.getListeners().empty());
    paintingMachine.clear();
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }

  TEST_F(NarratorTest, getListeners)
  {
    ls::Narrator narrator{};
    ASSERT_TRUE(narrator.getListeners().empty());
  }

  TEST_F(NarratorTest, removeListener)
  {
    this->createCars();
    ls::Narrator paintingMachine{};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes3));

    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes2));
    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes1));
    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes3));
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }

  TEST_F(NarratorTest, removeListener_no_listener_available)
  {
    this->createCars();
    ls::Narrator paintingMachine{};
    ASSERT_FALSE(paintingMachine.removeListener(this->mercedes2));
  }

  TEST_F(NarratorTest, removeListener_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::Narrator paintingMachine{};
                     paintingMachine.removeListener(nullptr);
                   }
                   catch (const ls::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::IllegalArgumentException);
  }

  TEST_F(NarratorTest, tell)
  {
    this->createCars();
    ls::Narrator paintingMachine{};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls::IListener>(this->mercedes3));

    ASSERT_STREQ("pink", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("blue", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("red", this->mercedes3->getColor().c_str());

    ls::String newColor{"black"};
    paintingMachine.tell(static_cast<const ls::Class &>(newColor));

    ASSERT_STREQ("black", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes3->getColor().c_str());
  }
}
