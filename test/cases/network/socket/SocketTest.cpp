/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-16
 * Changed:         2022-12-28
 *
 * */

#include <ls_std/ls_std_os.hpp>
#include <gtest/gtest.h>
#include <ls_std/ls_std_network.hpp>
#include <ls_std/ls_std_core.hpp>
#include <ls_std_core_test.hpp>
#include <ls_std_common_test.hpp>

using namespace ls::std::network;
using namespace ::testing;
using namespace ::std;
using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls_std_core_test;
using namespace ls_std_common_test;

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
        socketParameter.protocolFamilyType = ProtocolFamilyType::LS_STD_PROTOCOL_FAMILY_TYPE_IPV4;

        SocketAddress socketAddress{};
        socketAddress.protocolType = ProtocolType::LS_STD_PROTOCOL_TYPE_TCP;
        socketAddress.ipAddress = "127.0.0.1";
        socketAddress.port = 2220;
        socketParameter.socketAddress = socketAddress;

        return socketParameter;
      }
  };

  TEST_F(SocketTest, getClassName)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    ASSERT_STREQ("Socket", Socket{parameter}.getClassName().c_str());
  }

  TEST_F(SocketTest, read)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    shared_ptr<MockPosixReader> mockReader = make_shared<MockPosixReader>();
    parameter.posixSocket = mockSocket;
    parameter.posixReader = mockReader;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockReader, read(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockReader, read(_, _, _)).WillByDefault(Return(1));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    parameter.readBufferSize = 32;
    Socket socket{parameter};

    ASSERT_FALSE(socket.read().empty());
  }

  TEST_F(SocketTest, read_no_buffer_size_set)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     byte_field data = socket.read();
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(SocketTest, read_api_call_failed)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    shared_ptr<MockPosixReader> mockReader = make_shared<MockPosixReader>();
    parameter.posixSocket = mockSocket;
    parameter.posixReader = mockReader;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockReader, read(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockReader, read(_, _, _)).WillByDefault(Return(-1));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    parameter.readBufferSize = 32;
    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     byte_field data = socket.read();
                   }
                   catch (const FileOperationException &_exception)
                   {
                     throw;
                   }
                 }, FileOperationException);
  }

  TEST_F(SocketTest, write)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    shared_ptr<MockPosixWriter> mockWriter = make_shared<MockPosixWriter>();
    parameter.posixSocket = mockSocket;
    parameter.posixWriter = mockWriter;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockWriter, write(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockWriter, write(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    ASSERT_TRUE(socket.write("Hello Server!"));
  }

  TEST_F(SocketTest, accept)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, accept(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, accept(_, _, _)).WillByDefault(Return(15));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_EQ(2, socket.accept());
  }

  TEST_F(SocketTest, accept_wrong_protocol)
  {
    SocketParameter parameter = generateSocketParameter();
    parameter.socketAddress.protocolType = LS_STD_PROTOCOL_TYPE_UDP;

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     connection_id listened = socket.accept();
                   }
                   catch (const WrongProtocolException &_exception)
                   {
                     throw;
                   }
                 }, WrongProtocolException);
  }

  TEST_F(SocketTest, accept_not_accepted)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, accept(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, accept(_, _, _)).WillByDefault(Return(-1));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};

    EXPECT_THROW({
                   try
                   {
                     connection_id listened = socket.accept();
                   }
                   catch (const SocketOperationFailedException &_exception)
                   {
                     throw;
                   }
                 }, SocketOperationFailedException);
  }

  TEST_F(SocketTest, bind)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, bind(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, bind(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.bind());
  }

  TEST_F(SocketTest, close)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
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

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, connect(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, connect(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.connect());
  }

  TEST_F(SocketTest, handle)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, accept(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, accept(_, _, _)).WillByDefault(Return(5));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    connection_id acceptedConnection = socket.accept();
    ASSERT_TRUE(socket.handle(acceptedConnection));
  }

  TEST_F(SocketTest, handle_no_accepted_connection)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_FALSE(socket.handle(13));
  }

  TEST_F(SocketTest, handleV2)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.handle());
  }

  TEST_F(SocketTest, isInitialized)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.isInitialized());
  }

  TEST_F(SocketTest, listen)
  {
    SocketParameter parameter = generateSocketParameter();

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, listen(_, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, listen(_, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
    #endif

    Socket socket{parameter};
    ASSERT_TRUE(socket.listen());
  }

  TEST_F(SocketTest, listen_wrong_protocol)
  {
    SocketParameter parameter = generateSocketParameter();
    parameter.socketAddress.protocolType = LS_STD_PROTOCOL_TYPE_UDP;

    #if LS_STD_UNIX_PLATFORM
    shared_ptr<MockPosixSocket> mockSocket = make_shared<MockPosixSocket>();
    parameter.posixSocket = mockSocket;

    EXPECT_CALL(*mockSocket, create(_, _, _)).Times(AtLeast(1));
    ON_CALL(*mockSocket, create(_, _, _)).WillByDefault(Return(0));
    EXPECT_CALL(*mockSocket, close(_)).Times(AtLeast(1));
    ON_CALL(*mockSocket, close(_)).WillByDefault(Return(0));
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
