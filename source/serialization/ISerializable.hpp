/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-08-21
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

      virtual const ls_std::byte* Marshal() = 0;
      virtual void Unmarshal(const ls_std::byte* _data) = 0;
  };
}

#endif
