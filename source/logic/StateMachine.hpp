/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-05
 *
 * */

#ifndef LS_STD_STATE_MACHINE_HPP
#define LS_STD_STATE_MACHINE_HPP

#include <memory>
#include "../base/Class.hpp"
#include "State.hpp"

namespace ls_std {
  class StateMachine : public Class {
    public:

      StateMachine();
      ~StateMachine() = default;

    private:

      std::shared_ptr<State> currentState {};
  };
}

#endif
