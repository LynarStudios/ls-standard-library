/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-02
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_LIBRARY_VERSION_HPP
#define LS_STD_LIBRARY_VERSION_HPP

#include <string>

namespace ls::std::core
{
  static ::std::string getVersion() // TODO: create class to split up header / source files
  {
    return "2023.1.0";
  }
}

#endif
