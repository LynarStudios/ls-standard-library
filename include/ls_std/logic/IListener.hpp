/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_I_LISTENER_HPP
#define LS_STD_I_LISTENER_HPP

#include "../base/Class.hpp"

namespace ls_std {
  class IListener : public Class {
    public:

      IListener();
      ~IListener() override = default;

      virtual void listen(const ls_std::Class& _info) = 0;
  };
}

#endif
