/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/FileOperationException.hpp>

ls::std::core::FileOperationException::FileOperationException() = default;

ls::std::core::FileOperationException::~FileOperationException() = default;

const char *ls::std::core::FileOperationException::what() const noexcept
{
  return "FileOperationException thrown - file operation failed!";
}
