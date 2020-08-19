/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-19
 *
 * */

#ifndef I_STORABLE_HPP
#define I_STORABLE_HPP

#include "../base/Types.hpp"

namespace ls_std {
  class IStorable {
    public:
      IStorable() = default;
      ~IStorable() = default;

      virtual void load() = 0;
      virtual void save() = 0;
  };
}

#endif
