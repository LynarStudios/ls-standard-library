/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_I_READER_HPP
#define LS_STD_I_READER_HPP

#include <ls-std/core/types/Types.hpp>

namespace ls::std::core::interface_type
{
  class IReader
  {
    public:

      IReader() = default;
      ~IReader() = default;

      virtual ls::std::core::type::byte_field read() = 0;
  };
}

#endif
