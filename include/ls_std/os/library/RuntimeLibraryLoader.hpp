/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-10-20
 *
 * */

#ifndef LS_STD_RUNTIME_LIBRARY_LOADER_HPP
#define LS_STD_RUNTIME_LIBRARY_LOADER_HPP

#include "RuntimeLibraryLoaderParameter.hpp"
#include <unordered_map>

namespace ls::std::os
{
  class RuntimeLibraryLoader
  {
    public:

      explicit RuntimeLibraryLoader(ls::std::os::RuntimeLibraryLoaderParameter _parameter); // TODO: rename class to RuntimeLibrary? Should there be a validator check for file extensions?
      ~RuntimeLibraryLoader() = default;

      bool close();
      void* getSymbol(const ::std::string& _symbolName);
      bool hasSymbol(const ::std::string& _symbolName);
      bool loadSymbol(const ::std::string& _symbolName);
      bool open();

    private:

      #if defined(unix) || defined(__APPLE__)
      void* handle{};
      #endif
      ls::std::os::RuntimeLibraryLoaderParameter parameter{};
      #if defined(unix) || defined(__APPLE__)
      ::std::unordered_map<::std::string, void*> symbols{};
      #endif

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _close();
      [[nodiscard]] void* _getSymbolUnix(const ::std::string& _symbolName);
      [[nodiscard]] bool _hasSymbolUnix(const ::std::string& _symbolName);
      [[nodiscard]] bool _loadSymbolUnix(const ::std::string& _symbolName);
      [[nodiscard]] bool _openUnix();
      #endif
      #ifdef _WIN32
      bool _openWindows();
      #endif
  };
}

#endif
