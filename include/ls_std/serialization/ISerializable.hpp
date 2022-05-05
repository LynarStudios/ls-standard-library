/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_SERIALIZABLE_HPP
#define LS_STD_SERIALIZABLE_HPP

#include <ls_std/core/Types.hpp>

namespace ls
{
  class ISerializable
  {
    public:

      ISerializable() = default;
      ~ISerializable() = default;

      virtual ls::byte_field marshal() = 0;
      virtual void unmarshal(const ls::byte_field &_data) = 0;
  };
}

#endif
