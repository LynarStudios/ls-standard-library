/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2023-02-04
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::core::IllegalArithmeticOperationException::IllegalArithmeticOperationException() = default;

ls::std::core::IllegalArithmeticOperationException::~IllegalArithmeticOperationException() = default;

const char *ls::std::core::IllegalArithmeticOperationException::what() const noexcept
{
  return "IllegalArithmeticOperationException thrown - arithmetic operation is not allowed!";
}
