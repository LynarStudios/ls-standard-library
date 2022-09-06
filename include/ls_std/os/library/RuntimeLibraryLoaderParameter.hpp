/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-09-06
 *
 * */

#ifndef LS_STD_RUNTIME_LIBRARY_LOADER_PARAMETER_HPP
#define LS_STD_RUNTIME_LIBRARY_LOADER_PARAMETER_HPP

#include <string>

namespace ls::std::os
{
  struct RuntimeLibraryLoaderParameter
  {
    ::std::string path{};
  };
}

#endif
