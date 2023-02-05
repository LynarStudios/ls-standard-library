/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP
#define LS_STD_INCOMPLETE_JSON_EXCEPTION_HPP

#include <exception>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL IncompleteJsonException : public ::std::exception
  {
    public:

      IncompleteJsonException();
      ~IncompleteJsonException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
