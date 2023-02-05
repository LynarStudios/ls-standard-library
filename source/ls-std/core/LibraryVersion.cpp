/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <ls-std/core/LibraryVersion.hpp>

ls::std::core::LibraryVersion::LibraryVersion() = default;

ls::std::core::LibraryVersion::~LibraryVersion() = default;

::std::string ls::std::core::LibraryVersion::getVersion()
{
  return "2023.1.0";
}
