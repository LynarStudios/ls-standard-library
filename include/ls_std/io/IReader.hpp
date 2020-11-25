/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-11-20
 *
 * */

#ifndef LS_STD_I_READER_HPP
#define LS_STD_I_READER_HPP

#include <ls_std/base/Types.hpp>

namespace ls_std {
  class IReader {
    public:

      IReader() = default;
      ~IReader() = default;

      virtual ls_std::byte_field read() = 0;
  };
}

#endif