/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-06-29
 *
 * */

#ifndef LS_STD_ILLEGAL_OPERATION_EXCEPTION_HPP
#define LS_STD_ILLEGAL_OPERATION_EXCEPTION_HPP

#include <exception>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class DYNAMIC_GOAL IllegalArithmeticOperationException : public ::std::exception
      {
        public:

          IllegalArithmeticOperationException() = default;

          const char *what() const noexcept override
          {
            return "IllegalArithmeticOperationException thrown - arithmetic operation is not allowed!";
          }
      };
    }
  }
}

#endif
