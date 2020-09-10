/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include "../base/Class.hpp"
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"

namespace ls_std {
  class State : public Class {
    public:

      explicit State(StateId _id);
      ~State() = default;

      bool addStateConnection(const StateConnectionId& _connectionId, const std::shared_ptr<State>& _connectedState);
      std::unordered_map<StateConnectionId, StateConnection> getConnectedStates();
      StateId getId();

    private:

      std::unordered_map<StateConnectionId, StateConnection> connectedStates {};
      StateId id {};

      bool _stateIsConnected(const StateId& _id);
  };
}

#endif
