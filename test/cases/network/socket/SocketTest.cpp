/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-12-12
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>

using namespace ls::std::network;
using namespace ::testing;
using namespace ls_std_network_test;
using namespace ::std;
using namespace ls::std::core;

namespace
{
  class SocketTest : public ::testing::Test
  {
    protected:

      SocketTest() = default;
      ~SocketTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static SocketParameter generateSocketParameter()
      {
        SocketParameter socketParameter{};
        socketParameter.protocolFamilyType = ProtocolFamilyType::PROTOCOL_FAMILY_TYPE_IPV4;

        SocketAddress socketAddress{};
        socketAddress.protocolType = ProtocolType::PROTOCOL_TYPE_TCP;
        socketAddress.ipAddress = "127.0.0.1";
        socketAddress.port = 2220;
        socketParameter.socketAddress = socketAddress;

        return socketParameter;
      }
  };

  TEST_F(SocketTest, getClassName)
  {
    ASSERT_STREQ("Socket", Socket{generateSocketParameter()}.getClassName().c_str());
  }

  TEST_F(SocketTest, accept)
  {
    SocketParameter parameter = generateSocketParameter();

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, accept(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, accept(_, _, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.accept());
  }

  TEST_F(SocketTest, accept_wrong_protocol)
  {
    SocketParameter parameter = generateSocketParameter();
    parameter.socketAddress.protocolType = PROTOCOL_TYPE_UDP;

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     bool listened = socket.accept();
                   }
                   catch (const WrongProtocolException &_exception)
                   {
                     throw;
                   }
                 }, WrongProtocolException);
  }

  TEST_F(SocketTest, bind)
  {
    SocketParameter parameter = generateSocketParameter();

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, bind(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, bind(_, _, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.bind());
  }

  TEST_F(SocketTest, close)
  {
    SocketParameter parameter = generateSocketParameter();

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.close());
  }

  TEST_F(SocketTest, connect)
  {
    SocketParameter parameter = generateSocketParameter();

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, connect(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, connect(_, _, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.connect());
  }

  TEST_F(SocketTest, isInitialized)
  {
    Socket socket{generateSocketParameter()};
    ASSERT_TRUE(socket.isInitialized());
  }

  TEST_F(SocketTest, listen)
  {
    SocketParameter parameter = generateSocketParameter();

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, listen(_, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, listen(_, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.listen());
  }

  TEST_F(SocketTest, listen_wrong_protocol)
  {
    SocketParameter parameter = generateSocketParameter();
    parameter.socketAddress.protocolType = PROTOCOL_TYPE_UDP;

    #if defined(unix) || defined(__APPLE__)
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     bool listened = socket.listen();
                   }
                   catch (const WrongProtocolException &_exception)
                   {
                     throw;
                   }
                 }, WrongProtocolException);
  }
}
