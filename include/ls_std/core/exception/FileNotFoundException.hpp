/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP
#define LS_STD_FILE_NOT_FOUND_EXCEPTION_HPP

#include <exception>
#include <string>
#include <cstring>

//TODO: pass parameters, use class, show class name
namespace ls::std::core
{
  class FileNotFoundException : public ::std::exception
  {
    public:

      FileNotFoundException() = default;

      const char *what() const noexcept override
      {
        return "FileNotFoundException thrown - file not found!";
      };
  };
}

#endif
