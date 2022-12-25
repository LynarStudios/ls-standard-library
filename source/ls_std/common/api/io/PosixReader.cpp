/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-16
 * Changed:         2022-12-25
 *
 * */

#include <ls_std/common/api/io/PosixReader.hpp>

ls::std::common::api::PosixReader::PosixReader()
= default;

ls::std::common::api::PosixReader::~PosixReader()
= default;

size_t ls::std::common::api::PosixReader::read(int _unixFileDescriptor, void *_buffer, size_t _size)
{
  return ::read(_unixFileDescriptor, _buffer, _size);
}
