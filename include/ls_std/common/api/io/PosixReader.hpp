/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-16
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_POSIX_READER_HPP
#define LS_STD_POSIX_READER_HPP

#include <ls_std/common/interface/IPosixReader.hpp>

namespace ls::std::common::api
{
  class PosixReader : public ls::std::common::interface_type::IPosixReader
  {
    public:

      PosixReader();
      ~PosixReader() override;

      size_t read(int _unixFileDescriptor, void* _buffer, size_t _size) override;
  };
}

#endif
