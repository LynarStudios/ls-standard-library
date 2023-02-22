/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-22
 *
 * */

#include <gtest/gtest.h>
#include <ls-std-event-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-event.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::core::interface_type::IListener;
using ls::std::event::Narrator;
using std::make_shared;
using std::shared_ptr;
using test::event::Colour;
using test::event::TestDataMercedesCar;
using testing::Test;

namespace
{
  class NarratorTest : public Test
  {
    protected:

      NarratorTest() = default;
      ~NarratorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      shared_ptr<TestDataMercedesCar> mercedes1{};
      shared_ptr<TestDataMercedesCar> mercedes2{};
      shared_ptr<TestDataMercedesCar> mercedes3{};

      void createCars()
      {
        this->mercedes1 = make_shared<TestDataMercedesCar>();
        this->mercedes1->setColor("pink");
        this->mercedes2 = make_shared<TestDataMercedesCar>();
        this->mercedes2->setColor("blue");
        this->mercedes3 = make_shared<TestDataMercedesCar>();
        this->mercedes3->setColor("red");
      }
  };

  TEST_F(NarratorTest, addListener)
  {
    this->createCars();
    Narrator paintingMachine{};

    ASSERT_TRUE(paintingMachine.addListener(this->mercedes1));
    ASSERT_TRUE(paintingMachine.addListener(this->mercedes2));
    ASSERT_TRUE(paintingMachine.addListener(this->mercedes3));
  }

  TEST_F(NarratorTest, addListener_listener_already_exists)
  {
    this->createCars();
    Narrator paintingMachine{};

    ASSERT_TRUE(paintingMachine.addListener(this->mercedes1));
    ASSERT_FALSE(paintingMachine.addListener(this->mercedes1));
  }

  TEST_F(NarratorTest, addListener_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            Narrator paintingMachine{};
            paintingMachine.addListener(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(NarratorTest, clear)
  {
    this->createCars();
    Narrator paintingMachine{};
    paintingMachine.addListener(this->mercedes1);
    paintingMachine.addListener(this->mercedes2);
    paintingMachine.addListener(this->mercedes3);

    ASSERT_FALSE(paintingMachine.getListeners().empty());
    paintingMachine.clear();
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }

  TEST_F(NarratorTest, getListeners)
  {
    Narrator narrator{};
    ASSERT_TRUE(narrator.getListeners().empty());
  }

  TEST_F(NarratorTest, removeListener)
  {
    this->createCars();
    Narrator paintingMachine{};
    paintingMachine.addListener(this->mercedes1);
    paintingMachine.addListener(this->mercedes2);
    paintingMachine.addListener(this->mercedes3);

    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes2));
    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes1));
    ASSERT_TRUE(paintingMachine.removeListener(this->mercedes3));
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }

  TEST_F(NarratorTest, removeListener_no_listener_available)
  {
    this->createCars();
    Narrator paintingMachine{};
    ASSERT_FALSE(paintingMachine.removeListener(this->mercedes2));
  }

  TEST_F(NarratorTest, removeListener_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            Narrator paintingMachine{};
            paintingMachine.removeListener(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(NarratorTest, tell)
  {
    this->createCars();
    Narrator paintingMachine{};
    paintingMachine.addListener(this->mercedes1);
    paintingMachine.addListener(this->mercedes2);
    paintingMachine.addListener(this->mercedes3);

    ASSERT_STREQ("pink", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("blue", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("red", this->mercedes3->getColor().c_str());

    Colour newColor{"black"};
    paintingMachine.tell(static_cast<const Class &>(newColor));

    ASSERT_STREQ("black", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes3->getColor().c_str());
  }
}
