/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-16
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_core.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::api;
using namespace ls::std::core::interface_type;
using namespace ::std;

namespace
{
  class PosixSocketTest : public ::testing::Test // TODO: remove, when vtable issue has been clarified
  {
    protected:

      PosixSocketTest() = default;
      ~PosixSocketTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(PosixSocketTest, memory)
  {
    shared_ptr<IPosixSocket> posixSocket = make_shared<PosixSocket>();
    ASSERT_TRUE(posixSocket != nullptr);
  }
}
