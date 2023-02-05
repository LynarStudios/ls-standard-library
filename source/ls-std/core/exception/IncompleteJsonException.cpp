/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/IncompleteJsonException.hpp>

ls::std::core::IncompleteJsonException::IncompleteJsonException() = default;

ls::std::core::IncompleteJsonException::~IncompleteJsonException() = default;

const char *ls::std::core::IncompleteJsonException::what() const noexcept
{
  return "IncompleteJsonException thrown - this JSON string is incomplete.";
}
