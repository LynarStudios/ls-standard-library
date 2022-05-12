/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_I_STORABLE_HPP
#define LS_STD_I_STORABLE_HPP

#include <ls_std/core/types/Types.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class IStorable
      {
        public:

          IStorable() = default;
          ~IStorable() = default;

          virtual ls::std::core::type::byte_field load() = 0;
          virtual void save(const ls::std::core::type::byte_field &_data) = 0;
      };
    }
  }
}

#endif
