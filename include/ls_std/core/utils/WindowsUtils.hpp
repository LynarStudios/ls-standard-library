/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-06
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_WINDOWS_UTILS_HPP
#define LS_STD_WINDOWS_UTILS_HPP

#include <ls_std/core/types/Types.hpp>
#include <string>
#include <windows.h>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class WindowsUtils
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
  }
}

#endif
