/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-07-01
 *
 * */

#ifndef LS_STD_KV_PARSE_DATA_HPP
#define LS_STD_KV_PARSE_DATA_HPP

#include <string>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace io
    {
      struct DYNAMIC_GOAL KvParseParameter
      {
        ::std::string::size_type index{};
        ::std::string line{};
      };
    }
  }
}

#endif
