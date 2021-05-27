/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2021-05-02
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>

namespace
{
  class SerializableJsonDoubleTest : public ::testing::Test
  {
    protected:

      SerializableJsonDoubleTest() = default;
      ~SerializableJsonDoubleTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SerializableJsonDoubleTest, marshal)
  {
    ls_std::Double x{3.14159};
    ls_std::SerializableJsonDouble serializable{std::make_shared<ls_std::Double>(x)};
    ls_std::String jsonString{serializable.marshal()};

    ASSERT_TRUE(jsonString.contains(R"({"value":3.14159)"));
  }

  TEST_F(SerializableJsonDoubleTest, unmarshal)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);

    ASSERT_DOUBLE_EQ(14.2234, *x);

    ls_std::SerializableJsonDouble serializable{x};
    serializable.unmarshal(R"({"value":3.14159})");

    ASSERT_DOUBLE_EQ(3.14159, *x);
  }

  TEST_F(SerializableJsonDoubleTest, getValue)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);
    ls_std::SerializableJsonDouble serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);
  }

  TEST_F(SerializableJsonDoubleTest, setValue)
  {
    std::shared_ptr<ls_std::Double> x = std::make_shared<ls_std::Double>(14.2234);
    ls_std::SerializableJsonDouble serializable{x};
    ASSERT_TRUE(serializable.getValue() == x);

    x = std::make_shared<ls_std::Double>(3.145);
    serializable.setValue(x);
    ASSERT_TRUE(serializable.getValue() == x);
  }
}
