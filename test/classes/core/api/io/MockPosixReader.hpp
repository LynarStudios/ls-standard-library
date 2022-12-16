/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-16
 * Changed:         2022-12-16
 *
 * */

#ifndef LS_STD_MOCK_POSIX_READER_HPP
#define LS_STD_MOCK_POSIX_READER_HPP

#include <ls_std/ls_std_core.hpp>
#include <gmock/gmock.h>

namespace ls_std_core_test
{
  class MockPosixReader : public ls::std::core::interface_type::IPosixReader
  {
    public:

      MockPosixReader() = default;
      ~MockPosixReader() override = default;

      MOCK_METHOD(size_t, read, (int _unixFileDescriptor, void* _buffer, size_t _size), (override));
  };
}

#endif
