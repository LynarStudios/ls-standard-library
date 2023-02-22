/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#ifndef LS_STD_MOCK_FILE_READER_HPP
#define LS_STD_MOCK_FILE_READER_HPP

#include <gmock/gmock.h>
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/core/type/Types.hpp>

namespace test::io
{
  class MockFileReader : public ls::std::core::interface_type::IReader
  {
    public:

      MockFileReader();
      ~MockFileReader() override;

      MOCK_METHOD(ls::std::core::type::byte_field, read, (), (override));
  };
}

#endif
