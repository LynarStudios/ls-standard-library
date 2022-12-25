/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-25
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_MOCK_POSIX_WRITER_HPP
#define LS_STD_MOCK_POSIX_WRITER_HPP

#include <ls_std/ls_std_common.hpp>
#include <gmock/gmock.h>

namespace ls_std_common_test
{
  class MockPosixWriter : public ls::std::common::interface_type::IPosixWriter
  {
    public:

      MockPosixWriter() = default;
      ~MockPosixWriter() override = default;

      MOCK_METHOD(size_t, write, (int _unixFileDescriptor, void* _buffer, size_t _size), (override));
  };
}

#endif
