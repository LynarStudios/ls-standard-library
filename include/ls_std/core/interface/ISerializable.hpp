/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_SERIALIZABLE_HPP
#define LS_STD_SERIALIZABLE_HPP

#include <ls_std/core/types/Types.hpp>

namespace ls::std::core::interface_type
{
  class ISerializable
  {
    public:

      ISerializable() = default;
      ~ISerializable() = default;

      virtual ls::std::core::type::byte_field marshal() = 0;
      virtual void unmarshal(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
