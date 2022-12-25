/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-25
 * Changed:         2022-12-25
 *
 * */

#include <ls_std/common/api/io/PosixWriter.hpp>

ls::std::common::api::PosixWriter::PosixWriter()
= default;

ls::std::common::api::PosixWriter::~PosixWriter()
= default;

size_t ls::std::common::api::PosixWriter::write(int _unixFileDescriptor, void *_buffer, size_t _size)
{
  return ::write(_unixFileDescriptor, _buffer, _size);
}
