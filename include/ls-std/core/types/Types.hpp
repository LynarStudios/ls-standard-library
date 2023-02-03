/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_TYPES_HPP
#define LS_STD_TYPES_HPP

#include <string>
#include <ls-std/lib/nlohmann_json/include/nlohmann/json.hpp>

namespace ls::std::core::type
{
  using byte = char;
  using byte_field = ::std::string;
  using long_type = long long int;
  using version_type = uint16_t;
  using json = nlohmann::json;
}

#endif
