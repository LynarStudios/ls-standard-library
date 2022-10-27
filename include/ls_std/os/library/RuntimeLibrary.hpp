/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-10-27
 * Changed:         2022-10-27
 *
 * */

#ifndef LS_STD_RUNTIME_LIBRARY_HPP
#define LS_STD_RUNTIME_LIBRARY_HPP

#include <string>
#include <ls_std/os/library/goals/dynamic_goal.hpp>
#include <ls_std/core/types/RuntimeLibraryTypes.hpp>
#include <unordered_map>
#include <windows.h>

namespace ls::std::os
{
  class LS_STD_DYNAMIC_GOAL RuntimeLibrary
  {
    public:

      RuntimeLibrary() = default;
      ~RuntimeLibrary() = default;

      bool addSymbol(const ls::std::core::type::runtime_library_entry& _entry);
      void* getSymbol(const ::std::string& _symbolName);
      bool hasSymbol(const ::std::string& _symbolName);

    private:

      ::std::unordered_map<::std::string, void*> symbols{};

      [[nodiscard]] void* _getSymbol(const ::std::string& _symbolName);
      [[nodiscard]] bool _hasSymbol(const ::std::string& _symbolName);
      [[nodiscard]] bool _isValidEntry(const ls::std::core::type::runtime_library_entry& _entry);
  };
}

#endif
