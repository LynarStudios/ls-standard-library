/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP
#define LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP

#include <cstring>
#include <exception>
#include <string>

//TODO: pass parameters, use class, show class name
namespace ls::std::core
{
  class FileNotFoundException : public ::std::exception
  {
    public:

      FileNotFoundException() = default;

      [[nodiscard]] const char *what() const noexcept override
      {
        return "FileNotFoundException thrown - file not found!";
      };
  };
}

#endif
