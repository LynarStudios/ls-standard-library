/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-25
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_POSIX_WRITER_HPP
#define LS_STD_POSIX_WRITER_HPP

#include <ls_std/common/interface/IPosixWriter.hpp>

namespace ls::std::common::api
{
  class PosixWriter : public ls::std::common::interface_type::IPosixWriter
  {
    public:

      PosixWriter();
      ~PosixWriter() override;

      size_t write(int _unixFileDescriptor, void* _buffer, size_t _size) override;
  };
}

#endif
