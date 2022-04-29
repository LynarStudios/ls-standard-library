/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_I_WRITER_HPP
#define LS_STD_I_WRITER_HPP

#include <vector>
#include <ls_std/core/Types.hpp>

namespace ls_std
{
  class IWriter
  {
    public:

      IWriter() = default;
      ~IWriter() = default;

      virtual bool write(const ls_std::byte_field &_data) = 0;
  };
}

#endif
