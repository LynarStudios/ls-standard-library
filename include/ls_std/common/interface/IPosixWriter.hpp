/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-25
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_I_POSIX_WRITER_HPP
#define LS_STD_I_POSIX_WRITER_HPP

#include <unistd.h>

namespace ls::std::common::interface_type
{
  class IPosixWriter
  {
    public:

      IPosixWriter();
      virtual ~IPosixWriter();

      virtual size_t write(int _unixFileDescriptor, void* _buffer, size_t _size) = 0;
  };
}

#endif
