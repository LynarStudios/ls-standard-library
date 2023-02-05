/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_I_WRITER_HPP
#define LS_STD_I_WRITER_HPP

#include <ls-std/core/types/Types.hpp>
#include <vector>

namespace ls::std::core::interface_type
{
  class IWriter
  {
    public:

      IWriter();
      virtual ~IWriter();

      virtual bool write(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
