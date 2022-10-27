/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-10-27
 * Changed:         2022-10-27
 *
 * */

#ifndef LS_STD_RUNTIME_LIBRARY_TYPES_HPP
#define LS_STD_RUNTIME_LIBRARY_TYPES_HPP

#include <map>
#include <string>

namespace ls::std::core::type
{
  using runtime_library_entry = ::std::pair<::std::string, void*>;
}

#endif
