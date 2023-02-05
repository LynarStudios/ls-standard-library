/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP
#define LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP

#include <cstring>
#include <exception>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

//TODO: pass parameters, use class, show class name
namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL FileNotFoundException : public ::std::exception
  {
    public:

      FileNotFoundException();
      ~FileNotFoundException() override;

      [[nodiscard]] const char *what() const noexcept override;
  };
}

#endif
