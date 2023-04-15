/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-04-15
*
* */

#include <ls-std/core/LibraryVersion.hpp>

using ls::std::core::LibraryVersion;
using std::string;

LibraryVersion::LibraryVersion() = default;

LibraryVersion::~LibraryVersion() = default;

string LibraryVersion::getVersion()
{
  return "2023.3.0";
}
