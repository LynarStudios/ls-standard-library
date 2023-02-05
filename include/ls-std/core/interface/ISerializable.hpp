/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_I_SERIALIZABLE_HPP
#define LS_STD_I_SERIALIZABLE_HPP

#include <ls-std/core/types/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL ISerializable
  {
    public:

      ISerializable();
      virtual ~ISerializable();

      virtual ls::std::core::type::byte_field marshal() = 0;
      virtual void unmarshal(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
