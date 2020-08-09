/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-08-09
 *
 * */

#ifndef I_BOXING_HPP
#define I_BOXING_HPP

#include <string>

namespace ls_std {
  class IBoxing {
    public:

      IBoxing() = default;
      ~IBoxing() = default;

      virtual void parse(std::string parseText) = 0;
      virtual std::string toString() = 0;
  };
}

#endif
