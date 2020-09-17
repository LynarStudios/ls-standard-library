/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-17
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
      std::vector<ls_std::StateId> getMemory();
      std::string getName();
      std::unordered_map<StateId, std::shared_ptr<State>> getStates();
      bool hasState(const StateId& _id);
      bool proceed();
      void setName(std::string _name);
      bool setStartState(const StateId& _id);

    private:

      std::shared_ptr<State> currentState {};
      std::vector<ls_std::StateId> memory {};
      std::string name {};
      std::unordered_map<StateId, std::shared_ptr<State>> states {};

      std::vector<StateId> _getNextValidStates();
      void _remember(const StateId& _id);
      bool _hasState(const StateId& _id);
  };
}

#endif
