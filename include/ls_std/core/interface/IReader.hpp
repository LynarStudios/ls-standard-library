/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_I_READER_HPP
#define LS_STD_I_READER_HPP

#include "ls_std/core/types/Types.hpp"

namespace ls
{
  namespace std
  {
    namespace core
    {
      class IReader
      {
        public:

          IReader() = default;
          ~IReader() = default;

          virtual ls::std::core::type::byte_field read() = 0;
      };
    }
  }
}

#endif
