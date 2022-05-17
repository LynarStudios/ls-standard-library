/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2022-05-16
 *
 * */

#ifndef LS_STD_SERIALIZABLE_HPP
#define LS_STD_SERIALIZABLE_HPP

#include <ls_std/core/types/Types.hpp>

namespace ls
{
  namespace std
  {
    namespace core
    {
      namespace interface
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
    }
  }
}

#endif
