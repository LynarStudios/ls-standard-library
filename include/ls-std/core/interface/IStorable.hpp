/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_I_STORABLE_HPP
#define LS_STD_I_STORABLE_HPP

#include <ls-std/core/types/Types.hpp>

namespace ls::std::core::interface_type
{
  class IStorable
  {
    public:

      IStorable();
      ~IStorable();

      virtual ls::std::core::type::byte_field load() = 0;
      virtual void save(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
