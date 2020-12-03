/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "StateMachineTypes.hpp"

namespace ls_std {
  class StateConnection : public Class {
    public:

      explicit StateConnection(ls_std::StateConnectionId _connectionId, ls_std::StateId _stateId);
      ~StateConnection() override = default;

      StateConnectionId getConnectionId();
      ls_std::StateId getStateId();
      bool isPassable() const;
      void setConnectionId(ls_std::StateConnectionId _connectionId);
      void setStateId(ls_std::StateId _stateId);
      void updatePassCondition(bool _condition);

    private:

      bool condition {};
      ls_std::StateConnectionId connectionId {};
      ls_std::StateId stateId {};
  };
}

#endif
