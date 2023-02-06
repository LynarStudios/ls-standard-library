/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/NullPointerException.hpp>

ls::std::core::NullPointerException::NullPointerException() = default;

ls::std::core::NullPointerException::~NullPointerException() = default;

const char *ls::std::core::NullPointerException::what() const noexcept
{
  return "NullPointerException thrown - reference is null!";
}