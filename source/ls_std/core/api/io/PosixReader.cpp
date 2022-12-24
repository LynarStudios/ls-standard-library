/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-16
 * Changed:         2022-12-23
 *
 * */

#include <ls_std/core/api/io/PosixReader.hpp>

ls::std::core::api::PosixReader::PosixReader()
= default;

ls::std::core::api::PosixReader::~PosixReader()
= default;

size_t ls::std::core::api::PosixReader::read(int _unixFileDescriptor, void *_buffer, size_t _size)
{
  return ::read(_unixFileDescriptor, _buffer, _size);
}
