/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-09-06
 *
 * */

#ifndef LS_STD_RUNTIME_LIBRARY_LOADER_HPP
#define LS_STD_RUNTIME_LIBRARY_LOADER_HPP

#include "RuntimeLibraryLoaderParameter.hpp"

namespace ls::std::os
{
  class RuntimeLibraryLoader
  {
    public:

      explicit RuntimeLibraryLoader(ls::std::os::RuntimeLibraryLoaderParameter _parameter);
      ~RuntimeLibraryLoader() = default;

    private:

      ls::std::os::RuntimeLibraryLoaderParameter parameter{};
  };
}

#endif
