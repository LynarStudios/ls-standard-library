/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2020-11-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std/logic/Narrator.hpp>
#include "../../classes/observer/TestDataMercedesCar.hpp"

namespace {
  class NarratorTest : public ::testing::Test {
    protected:

      NarratorTest() = default;
      ~NarratorTest() override = default;

      void SetUp() override {}
      void TearDown() override {}

      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes1 {};
      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes2 {};
      std::shared_ptr<ls_std_test::TestDataMercedesCar> mercedes3 {};

      void createCars() {
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
    ls_std::Narrator paintingMachine {};
    ASSERT_TRUE(paintingMachine.getListeners().empty());
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes1));
    ASSERT_EQ(1, paintingMachine.getListeners().size());
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes2));
    ASSERT_EQ(2, paintingMachine.getListeners().size());
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes3));
    ASSERT_EQ(3, paintingMachine.getListeners().size());
  }

  TEST_F(NarratorTest, clear)
  {
    this->createCars();
    ls_std::Narrator paintingMachine {};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes3));

    ASSERT_FALSE(paintingMachine.getListeners().empty());
    paintingMachine.clear();
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }

  TEST_F(NarratorTest, getListeners)
  {
    ls_std::Narrator narrator {};
    ASSERT_TRUE(narrator.getListeners().empty());
  }

  TEST_F(NarratorTest, notifyListeners)
  {
    this->createCars();
    ls_std::Narrator paintingMachine {};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes3));

    ASSERT_STREQ("pink", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("blue", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("red", this->mercedes3->getColor().c_str());

    ls_std::String newColor {"black"};
    paintingMachine.notifyListeners(static_cast<const ls_std::Class&>(newColor));

    ASSERT_STREQ("black", this->mercedes1->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes2->getColor().c_str());
    ASSERT_STREQ("black", this->mercedes3->getColor().c_str());
  }

  TEST_F(NarratorTest, removeListener)
  {
    this->createCars();
    ls_std::Narrator paintingMachine {};
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes1));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes2));
    paintingMachine.addListener(std::dynamic_pointer_cast<ls_std::IListener>(this->mercedes3));
    ASSERT_EQ(3, paintingMachine.getListeners().size());

    paintingMachine.removeListener(this->mercedes2);
    ASSERT_EQ(2, paintingMachine.getListeners().size());
    paintingMachine.removeListener(this->mercedes1);
    ASSERT_EQ(1, paintingMachine.getListeners().size());
    paintingMachine.removeListener(this->mercedes3);
    ASSERT_EQ(0, paintingMachine.getListeners().size());
    ASSERT_TRUE(paintingMachine.getListeners().empty());

    paintingMachine.removeListener(nullptr);
    ASSERT_EQ(0, paintingMachine.getListeners().size());
    ASSERT_TRUE(paintingMachine.getListeners().empty());
  }
}
