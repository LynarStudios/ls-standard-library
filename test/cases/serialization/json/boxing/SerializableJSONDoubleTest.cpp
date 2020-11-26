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
  class SerializableJSONDoubleTest : public ::testing::Test {
    protected:

      SerializableJSONDoubleTest() = default;
      ~SerializableJSONDoubleTest() override = default;

      void SetUp() override {}
      void TearDown() override {}
  };

  TEST_F(SerializableJSONDoubleTest, marshal)
  {
    ls_std::Double x {3.14159};
    ls_std::SerializableJSONDouble serializable {std::make_shared<ls_std::Double>(x)};
    ls_std::String jsonString {serializable.marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));
  }

  TEST_F(SerializableJSONDoubleTest, unmarshal)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);

    ASSERT_DOUBLE_EQ(14.2234, *x);

    ls_std::SerializableJSONDouble serializable {x};
    serializable.unmarshal(R"({"value":3.14159})");

    ASSERT_DOUBLE_EQ(3.14159, *x);
  }

  TEST_F(SerializableJSONDoubleTest, getValue)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);
    ls_std::SerializableJSONDouble serializable {x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJSONDoubleTest, setValue)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);
    ls_std::SerializableJSONDouble serializable {x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Double>(3.145);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
