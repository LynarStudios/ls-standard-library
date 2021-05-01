/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_KV_PARSE_DATA_HPP
#define LS_STD_KV_PARSE_DATA_HPP

#include <string>
#include <ls_std/boxing/String.hpp>

namespace ls_std
{
  struct KVParseData
  {
    std::string::size_type index{};
    ls_std::String line{};
  };
}

#endif
