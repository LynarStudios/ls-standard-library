/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_SERIALIZABLE_HPP
#define LS_STD_SERIALIZABLE_HPP

#include <ls_std/base/Types.hpp>

namespace ls_std
{
  class ISerializable
  {
    public:

      ISerializable() = default;
      ~ISerializable() = default;

      virtual ls_std::byte_field marshal() = 0;
      virtual void unmarshal(const ls_std::byte_field &_data) = 0;
  };
}

#endif
