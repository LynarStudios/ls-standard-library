/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-11-26
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace {
  class SerializableJSONFloatTest : public ::testing::Test {
    protected:

      SerializableJSONFloatTest() = default;
      ~SerializableJSONFloatTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONFloatTest, marshal)
  {
    ls_std::Float x {3.14159f};
    ls_std::SerializableJSONFloat serializable {std::make_shared<ls_std::Float>(x)};
    ls_std::String jsonString {serializable.marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));
  }

  TEST_F(SerializableJSONFloatTest, unmarshal)
  {
    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>(14.2234f);
    ASSERT_FLOAT_EQ(14.2234f, *x);

    ls_std::SerializableJSONFloat serializable {x};
    serializable.unmarshal(R"({"value":3.14159})");

    ASSERT_FLOAT_EQ(3.14159f, *x);
  }

  TEST_F(SerializableJSONFloatTest, getValue)
  {
    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>(14.2234f);
    ls_std::SerializableJSONFloat serializable {x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJSONFloatTest, setValue)
  {
    std::shared_ptr<ls_std::Float> x = std::make_shared<ls_std::Float>(14.2234f);
    ls_std::SerializableJSONFloat serializable {x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Float>(3.134f);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
