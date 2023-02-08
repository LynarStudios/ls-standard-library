/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2023-02-08
 *
 * */

#ifndef LS_STD_I_STORABLE_HPP
#define LS_STD_I_STORABLE_HPP

#include <ls-std/core/type/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IStorable
  {
    public:

      IStorable();
      virtual ~IStorable();

      virtual ls::std::core::type::byte_field load() = 0;
      virtual void save(const ls::std::core::type::byte_field &_data) = 0;
  };
}

#endif
