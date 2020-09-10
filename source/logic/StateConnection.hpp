/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-09-10
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <atomic>
#include "../base/Class.hpp"
#include "StateMachineTypes.hpp"

namespace ls_std {
  class StateConnection : public Class {
    public:

      explicit StateConnection(StateConnectionId _connectionId, StateId _stateId);
      ~StateConnection() = default;

      StateConnectionId getConnectionId();
      StateId getStateId();
      bool isPassable();
      void updatePassCondition(bool _condition);

    private:

      std::atomic<bool> condition {};
      StateConnectionId connectionId {};
      StateId stateId {};
  };
}

#endif
