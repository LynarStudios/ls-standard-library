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

      bool open();

    private:

      #if defined(unix) || defined(__APPLE__)
      void* handle{};
      #endif
      ls::std::os::RuntimeLibraryLoaderParameter parameter{};

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _openUnix();
      #endif
      #ifdef _WIN32
      bool _openWindows();
      #endif
  };
}

#endif
