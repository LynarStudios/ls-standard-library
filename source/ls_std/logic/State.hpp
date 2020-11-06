/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include "../../../include/ls_std/base/Class.hpp"
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"

namespace ls_std {
  class State : public Class {
    public:

      explicit State(StateId _id);
      ~State() = default;

      bool addStateConnection(const StateConnectionId& _connectionId, const std::shared_ptr<State>& _connectedState);
      bool addStateConnection(const std::shared_ptr<StateConnection>& _connection);
      void clearConnections();
      std::unordered_map<StateConnectionId, std::shared_ptr<StateConnection>> getConnectedStates();
      StateId getId();
      bool hasConnection(const StateConnectionId& _connectionId);
      void setId(StateId _id);

    private:

      std::unordered_map<StateConnectionId, std::shared_ptr<StateConnection>> connectedStates {};
      StateId id {};

      void _clearConnections();
      bool _hasConnection(const StateConnectionId& _connectionId);
  };
}

#endif
