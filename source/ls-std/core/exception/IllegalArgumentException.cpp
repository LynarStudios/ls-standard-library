/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::core::IllegalArgumentException::IllegalArgumentException() = default;

ls::std::core::IllegalArgumentException::~IllegalArgumentException() = default;

const char *ls::std::core::IllegalArgumentException::what() const noexcept
{
  return "IllegalArgumentException thrown - passed argument is not valid!";
}
