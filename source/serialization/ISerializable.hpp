/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-08-23
 *
 * */

#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include "../base/Types.hpp"

namespace ls_std {
  class ISerializable {
    public:

      ISerializable() = default;
      ~ISerializable() = default;

      virtual ls_std::byte_field marshal() = 0;
      virtual void unmarshal(const ls_std::byte_field& _data) = 0;
  };
}

#endif
