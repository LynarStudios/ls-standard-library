/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2021-05-30
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <TestHelper.hpp>

namespace
{
  class BooleanTest : public ::testing::Test
  {
    protected:

      BooleanTest() = default;
      ~BooleanTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static std::pair<std::shared_ptr<ls_std::File>, std::shared_ptr<ls_std::Boolean>> createTestExpression()
      {
        std::shared_ptr<ls_std::Boolean> expression = std::make_shared<ls_std::Boolean>();
        std::string path = TestHelper::getResourcesFolderLocation() + "tmp_storable_bool.json";
        std::shared_ptr<ls_std::File> file = std::make_shared<ls_std::File>(path);
        file->createNewFile();
        ls_std::FileWriter writer{*file};
        writer.write(R"({"value":true})");

        auto serializable = std::make_shared<ls_std::SerializableJsonBoolean>(expression);
        expression->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

        auto storable = std::make_shared<ls_std::StorableFile>(path);
        expression->setStorable(std::dynamic_pointer_cast<ls_std::IStorable>(storable));

        return std::pair<std::shared_ptr<ls_std::File>, std::shared_ptr<ls_std::Boolean>>(file, expression);
      }
  };

  // assignment operators

  TEST_F(BooleanTest, operator_assignment_boolean)
  {
    ls_std::Boolean expression{};
    expression = true;

    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, operator_assignment_integer)
  {
    ls_std::Boolean expression{};
    expression = 1;

    ASSERT_TRUE(expression);
  }

  // stream operators

  TEST_F(BooleanTest, operator_output_stream)
  {
    ls_std::Boolean expression{true};
    std::ostringstream _stream{};
    _stream << expression;

    ASSERT_STREQ("true", _stream.str().c_str());
  }

  // logical operators

  TEST_F(BooleanTest, operator_negation_negative_value)
  {
    ls_std::Boolean expression{};
    ASSERT_TRUE(!expression);
  }

  TEST_F(BooleanTest, operator_negation_positive_value)
  {
    ls_std::Boolean expression{true};
    ASSERT_FALSE(!expression);
  }

  TEST_F(BooleanTest, operator_and)
  {
    ls_std::Boolean expressionA{true};
    ls_std::Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA && expressionB);
    ASSERT_TRUE(expressionB && expressionA);
    ASSERT_TRUE(expressionA && true);
    ASSERT_TRUE(expressionA && 1);
    ASSERT_TRUE(1 && expressionB);
  }

  TEST_F(BooleanTest, operator_and_with_false_result)
  {
    ls_std::Boolean expressionA{true};
    ls_std::Boolean expressionB{3 == 4};

    ASSERT_FALSE(expressionA && expressionB);
    ASSERT_FALSE(expressionB && expressionA);
    ASSERT_FALSE(expressionB && (3 == 4));
    ASSERT_FALSE(expressionB && 0);
    ASSERT_FALSE(expressionB && false);
  }

  TEST_F(BooleanTest, operator_or)
  {
    ls_std::Boolean expressionA{false};
    ls_std::Boolean expressionB{3 == 3};

    ASSERT_TRUE(expressionA || expressionB);
    ASSERT_TRUE(expressionB || expressionA);
    ASSERT_TRUE(expressionA || 1);
    ASSERT_TRUE(expressionA || true);
    ASSERT_TRUE(1 || expressionA);
  }

  TEST_F(BooleanTest, operator_or_with_false_result)
  {
    ls_std::Boolean expressionA{false};
    ls_std::Boolean expressionB{3 == 4};

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

    auto storableExpression = createTestExpression();

    // check

    storableExpression.second->load();
    ASSERT_TRUE(*storableExpression.second);

    storableExpression.first->remove();
  }

  TEST_F(BooleanTest, marshal_positive_value)
  {
    std::shared_ptr<ls_std::Boolean> expression = std::make_shared<ls_std::Boolean>(true);

    auto serializable = std::make_shared<ls_std::SerializableJsonBoolean>(expression);
    expression->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    ASSERT_STREQ(R"({"value":true})", expression->marshal().c_str());
  }

  TEST_F(BooleanTest, marshal_negative_value)
  {
    std::shared_ptr<ls_std::Boolean> expression = std::make_shared<ls_std::Boolean>(false);

    auto serializable = std::make_shared<ls_std::SerializableJsonBoolean>(expression);
    expression->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));

    ASSERT_STREQ(R"({"value":false})", expression->marshal().c_str());
  }

  TEST_F(BooleanTest, parse_true_value)
  {
    ls_std::Boolean expression{};

    expression.parse("true");
    ASSERT_TRUE(expression);

    expression.parse("tRue");
    ASSERT_TRUE(expression);

    expression.parse("TRUE");
    ASSERT_TRUE(expression);
  }

  TEST_F(BooleanTest, parse_false_value)
  {
    ls_std::Boolean expression{};

    expression.parse("false");
    ASSERT_FALSE(expression);

    expression.parse("fAlSe");
    ASSERT_FALSE(expression);

    expression.parse("FALSE");
    ASSERT_FALSE(expression);
  }

  TEST_F(BooleanTest, toString_true)
  {
    ls_std::Boolean expression{2 < 3};
    ASSERT_STREQ("true", expression.toString().c_str());
  }

  TEST_F(BooleanTest, toString_false)
  {
    ls_std::Boolean expression{4 < 3};
    ASSERT_STREQ("false", expression.toString().c_str());
  }

  TEST_F(BooleanTest, unmarshal)
  {
    std::shared_ptr<ls_std::Boolean> expression = std::make_shared<ls_std::Boolean>(false);
    auto serializable = std::make_shared<ls_std::SerializableJsonBoolean>(expression);
    expression->setSerializable(std::dynamic_pointer_cast<ls_std::ISerializable>(serializable));
    expression->unmarshal(R"({"value":true})");

    ASSERT_TRUE(*expression);
  }

  // additional functionality

  TEST_F(BooleanTest, getValue)
  {
    ls_std::Boolean x{2 < 3};
    ASSERT_TRUE(x.getValue());
  }

  TEST_F(BooleanTest, setSerialiable_no_reference)
  {
    ls_std::Boolean expression{};

    EXPECT_THROW({
                   try
                   {
                     expression.setSerializable(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(BooleanTest, setStorable_no_reference)
  {
    ls_std::Boolean expression{};

    EXPECT_THROW({
                   try
                   {
                     expression.setStorable(nullptr);
                   }
                   catch (const ls_std::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls_std::IllegalArgumentException);
  }

  TEST_F(BooleanTest, XOR_with_positive_result)
  {
    ls_std::Boolean x{2 < 3};
    ls_std::Boolean y{4 < 3};

    ASSERT_TRUE(ls_std::Boolean::XOR(x, y));
    ASSERT_TRUE(ls_std::Boolean::XOR(y, x));
    ASSERT_TRUE(ls_std::Boolean::XOR(y, true));
    ASSERT_TRUE(ls_std::Boolean::XOR(true, y));
    ASSERT_TRUE(ls_std::Boolean::XOR(true, false));
    ASSERT_TRUE(ls_std::Boolean::XOR(false, true));
  }

  TEST_F(BooleanTest, XOR_with_negative_result)
  {
    ls_std::Boolean w{};
    ls_std::Boolean x{true};
    ls_std::Boolean y{};
    ls_std::Boolean z{true};

    ASSERT_FALSE(ls_std::Boolean::XOR(x, z));
    ASSERT_FALSE(ls_std::Boolean::XOR(w, y));
    ASSERT_FALSE(ls_std::Boolean::XOR(true, true));
    ASSERT_FALSE(ls_std::Boolean::XOR(false, false));
    ASSERT_FALSE(ls_std::Boolean::XOR(w, false));
    ASSERT_FALSE(ls_std::Boolean::XOR(false, w));
  }
}
