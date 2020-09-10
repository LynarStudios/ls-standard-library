/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#ifndef LS_STD_STATE_MACHINE_HPP
#define LS_STD_STATE_MACHINE_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include "../base/Class.hpp"
#include "State.hpp"
#include "StateMachineTypes.hpp"

namespace ls_std {
  class StateMachine : public Class {
    public:

      explicit StateMachine(std::string _name);
      ~StateMachine() = default;

      bool addState(const std::shared_ptr<State>& _state);
      std::shared_ptr<State> getCurrentState();
      std::string getName();
      bool proceed();
      bool setStartState(const StateId& _id);

    private:

      std::shared_ptr<State> currentState {};
      std::string name {};
      std::unordered_map<StateId, std::shared_ptr<State>> states {};

      std::vector<StateId> _getNextValidStates();
      bool _stateExists(const StateId& _id);
  };
}

#endif
