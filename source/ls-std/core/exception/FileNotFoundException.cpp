/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/FileNotFoundException.hpp>

ls::std::core::FileNotFoundException::FileNotFoundException() = default;

ls::std::core::FileNotFoundException::~FileNotFoundException() = default;

const char *ls::std::core::FileNotFoundException::what() const noexcept
{
  return "FileNotFoundException thrown - file not found!";
}
