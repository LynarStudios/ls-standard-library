/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-15
 * Changed:         2022-12-23
 *
 * */

#ifndef LS_STD_I_POSIX_READER_HPP
#define LS_STD_I_POSIX_READER_HPP

#include <unistd.h>

namespace ls::std::core::interface_type
{
  class IPosixReader
  {
    public:

      IPosixReader();
      virtual ~IPosixReader();

      virtual size_t read(int _unixFileDescriptor, void* _buffer, size_t _size) = 0;
  };
}

#endif
