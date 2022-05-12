/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_KV_PARSE_DATA_HPP
#define LS_STD_KV_PARSE_DATA_HPP

#include <string>
#include <ls_std/boxing/String.hpp> // FIXME: remove "boxing" dependency from "io" module

namespace ls
{
  namespace std
  {
    namespace io
    {
      struct KvParseParameter
      {
        ::std::string::size_type index{};
        ls::std::boxing::String line{};
      };
    }
  }
}

#endif
