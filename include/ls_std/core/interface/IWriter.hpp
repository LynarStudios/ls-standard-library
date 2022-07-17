/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_I_WRITER_HPP
#define LS_STD_I_WRITER_HPP

#include <vector>
#include <ls_std/core/types/Types.hpp>

namespace ls::std::core::interface_type
{
  class IWriter
  {
    public:

      IWriter() = default;
      ~IWriter() = default;

      virtual bool write(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
