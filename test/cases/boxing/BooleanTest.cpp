/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-09-14
 *
 * */

#include <gtest/gtest.h>
#include "../../../source/boxing/Boolean.hpp"
#include "../../../source/serialization/json/boxing/SerializableJSONBoolean.hpp"
#include "../../TestHelper.hpp"
#include "../../../source/io/File.hpp"
#include "../../../source/io/FileWriter.hpp"
#include "../../../source/io/StorableFile.hpp"

namespace {
  class BooleanTest : public ::testing::Test {
    protected:

      BooleanTest() = default;
      ~BooleanTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  // assignment operators

  TEST_F(BooleanTest, operatorAssignment)
  {
    ls_std::Boolean expression {};

    expression = true;
    ASSERT_TRUE(expression);

    expression = 1;
    ASSERT_TRUE(expression);
  }

  // stream operators

  TEST_F(BooleanTest, operatorOutputStream)
  {
    ls_std::Boolean expression {true};
    std::ostringstream _stream {};
    _stream << expression;

    ASSERT_STREQ("true", _stream.str().c_str());
  }

  // logical operators

  TEST_F(BooleanTest, operatorNot) {
    ls_std::Boolean expression {};
    ASSERT_TRUE(!expression);
  }

  TEST_F(BooleanTest, operatorNotNegative) {
    ls_std::Boolean expression {true};
    ASSERT_FALSE(!expression);
  }

  TEST_F(BooleanTest, operatorAnd) {
    ls_std::Boolean expressionA {true};
    ls_std::Boolean expressionB {3 == 3};

    ASSERT_TRUE(expressionA && expressionB);
    ASSERT_TRUE(expressionB && expressionA);
    ASSERT_TRUE(expressionA && true);
    ASSERT_TRUE(expressionA && 1);
    ASSERT_TRUE(1 && expressionB);
  }

  TEST_F(BooleanTest, operatorAndNegative) {
    ls_std::Boolean expressionA {true};
    ls_std::Boolean expressionB {3 == 4};

    ASSERT_FALSE(expressionA && expressionB);
    ASSERT_FALSE(expressionB && expressionA);
    ASSERT_FALSE(expressionB && (3 == 4));
    ASSERT_FALSE(expressionB && 0);
    ASSERT_FALSE(expressionB && false);
  }

  TEST_F(BooleanTest, operatorOr) {
    ls_std::Boolean expressionA {false};
    ls_std::Boolean expressionB {3 == 3};

    ASSERT_TRUE(expressionA || expressionB);
    ASSERT_TRUE(expressionB || expressionA);
    ASSERT_TRUE(expressionA || 1);
    ASSERT_TRUE(expressionA || true);
    ASSERT_TRUE(1 || expressionA);
  }

  TEST_F(BooleanTest, operatorOrNegative) {
    ls_std::Boolean expressionA {false};
    ls_std::Boolean expressionB {3 == 4};

    ASSERT_FALSE(expressionA || expressionB);
    ASSERT_FALSE(expressionB || expressionA);
    ASSERT_FALSE(expressionA || 0);
    ASSERT_FALSE(expressionA || false);
    ASSERT_FALSE(0 || expressionA);
  }

  // implementation

  TEST_F(BooleanTest, load)
  {
    // preparation

    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>();
    std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_bool.json";
    ls_std::File file {path};
    file.createNewFile();
    ls_std::FileWriter writer {file};
    writer.write(R"({"value":true})");

    auto serializable = std::make_shared<ls_std::SerializableJSONBoolean>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    auto storable = std::make_shared<ls_std::StorableFile>(path);
    x->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

    // check

    x->load();
    ASSERT_TRUE(*x);

    file.remove();
  }

  TEST_F(BooleanTest, marshal)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(true);

    auto serializable = std::make_shared<ls_std::SerializableJSONBoolean>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    ASSERT_STREQ(R"({"value":true})", x->marshal().c_str());

    *x = false;
    ASSERT_STREQ(R"({"value":false})", x->marshal().c_str());
  }

  TEST_F(BooleanTest, parse)
  {
    ls_std::Boolean expression {};

    expression.parse("true");
    ASSERT_TRUE(expression);

    expression.parse("tRue");
    ASSERT_TRUE(expression);

    expression.parse("TRUE");
    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, parseNegative)
  {
    ls_std::Boolean expression {};

    expression.parse("false");
    ASSERT_FALSE(expression);

    expression.parse("fAlSe");
    ASSERT_FALSE(expression);

    expression.parse("FALSE");
    ASSERT_FALSE(expression);
  }

  TEST_F(BooleanTest, toString)
  {
    ls_std::Boolean expression { 2 < 3};
    ASSERT_STREQ("true", expression.toString().c_str());

    expression = 4 < 3;
    ASSERT_STREQ("false", expression.toString().c_str());
  }

  TEST_F(BooleanTest, unmarshal)
  {
    std::shared_ptr<ls_std::Boolean> x = std::make_shared<ls_std::Boolean>(false);

    ASSERT_FALSE(*x);

    auto serializable = std::make_shared<ls_std::SerializableJSONBoolean>(x);
    x->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    x->unmarshal(R"({"value":true})");

    ASSERT_TRUE(*x);
  }

  // additional functionality

  TEST_F(BooleanTest, getValue)
  {
    ls_std::Boolean x {2 < 3};
    ASSERT_TRUE(x.getValue());
  }

  TEST_F(BooleanTest, XOR)
  {
    ls_std::Boolean x {2 < 3};
    ls_std::Boolean y {4 < 3};

    ASSERT_TRUE(ls_std::Boolean::XOR(x, y));
    ASSERT_TRUE(ls_std::Boolean::XOR(y, x));
    ASSERT_TRUE(ls_std::Boolean::XOR(y, true));
    ASSERT_TRUE(ls_std::Boolean::XOR(true, y));
    ASSERT_TRUE(ls_std::Boolean::XOR(true, false));
    ASSERT_TRUE(ls_std::Boolean::XOR(false, true));
  }

  TEST_F(BooleanTest, XORNegative)
  {
    ls_std::Boolean w {};
    ls_std::Boolean x {true};
    ls_std::Boolean y {};
    ls_std::Boolean z {true};

    ASSERT_FALSE(ls_std::Boolean::XOR(x, z));
    ASSERT_FALSE(ls_std::Boolean::XOR(w, y));
    ASSERT_FALSE(ls_std::Boolean::XOR(true, true));
    ASSERT_FALSE(ls_std::Boolean::XOR(false, false));
    ASSERT_FALSE(ls_std::Boolean::XOR(w, false));
    ASSERT_FALSE(ls_std::Boolean::XOR(false, w));
  }
}
