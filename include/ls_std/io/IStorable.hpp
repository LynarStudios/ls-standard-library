/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_I_STORABLE_HPP
#define LS_STD_I_STORABLE_HPP

#include <ls_std/core/Types.hpp>

namespace ls
{
  class IStorable
  {
    public:
      IStorable() = default;
      ~IStorable() = default;

      virtual ls::std::core::byte_field load() = 0;
      virtual void save(const ls::std::core::byte_field &_data) = 0;
  };
}

#endif
