/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-07
 *
 * */

#ifndef LS_STD_STATE_MACHINE_HPP
#define LS_STD_STATE_MACHINE_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include "../base/Class.hpp"
#include "State.hpp"

namespace ls_std {
  class StateMachine : public Class {
    public:

      StateMachine();
      ~StateMachine() = default;

      bool addState(std::shared_ptr<State> _state);
      bool proceed();
      bool setStartState(const std::string& _id);

    private:

      std::shared_ptr<State> currentState {};
      std::unordered_map<std::string, std::shared_ptr<State>> states {};

      bool _stateExists(const std::string& _id);
  };
}

#endif
