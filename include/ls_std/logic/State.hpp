/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/base/Class.hpp>
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"

namespace ls_std {
  class State : public ls_std::Class {
    public:

      explicit State(ls_std::StateId _id);
      ~State() override = default;

      bool addStateConnection(const ls_std::StateConnectionId& _connectionId, const std::shared_ptr<ls_std::State>& _connectedState);
      bool addStateConnection(const std::shared_ptr<ls_std::StateConnection>& _connection);
      void clearConnections();
      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> getConnectedStates();
      ls_std::StateId getId();
      bool hasConnection(const ls_std::StateConnectionId& _connectionId);
      void setId(ls_std::StateId _id);

    private:

      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> connectedStates {};
      ls_std::StateId id {};

      void _clearConnections();
      bool _hasConnection(const ls_std::StateConnectionId& _connectionId);
  };
}

#endif
