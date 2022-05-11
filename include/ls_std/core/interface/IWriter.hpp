/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_I_WRITER_HPP
#define LS_STD_I_WRITER_HPP

#include <vector>
#include "ls_std/core/Types.hpp"

namespace ls
{
  namespace std
  {
    namespace core
    {
      class IWriter
      {
        public:

          IWriter() = default;
          ~IWriter() = default;

          virtual bool write(const ls::std::core::byte_field &_data) = 0;
      };
    }
  }
}

#endif
