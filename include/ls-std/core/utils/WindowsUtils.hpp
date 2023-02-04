/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-06
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_WINDOWS_UTILS_HPP
#define LS_STD_WINDOWS_UTILS_HPP

#include <ls-std/core/types/Types.hpp>
#include <string>
#include <windows.h>

namespace ls::std::core
{
  class WindowsUtils // TODO: migrate to header / source split approach
  {
    public:

      WindowsUtils() = default;
      ~WindowsUtils() = default;

      static ::std::string getMessageFromErrorCode(const int &_errorCode)
      {
        ls::std::core::type::byte messageBuffer[256 + 1];
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, _errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), messageBuffer, sizeof(messageBuffer), nullptr);

        return ::std::string{messageBuffer};
      }
  };
}

#endif
