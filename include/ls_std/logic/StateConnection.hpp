/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "StateMachineTypes.hpp"

namespace ls
{
  class StateConnection : public ls::Class
  {
    public:

      explicit StateConnection(const ls::StateConnectionId& _connectionId, const ls::StateId& _stateId);
      ~StateConnection() override = default;

      StateConnectionId getConnectionId();
      ls::StateId getStateId();
      bool isPassable() const;
      void setConnectionId(const ls::StateConnectionId& _connectionId);
      void setStateId(const ls::StateId& _stateId);
      void updatePassCondition(bool _condition);

    private:

      bool condition{};
      ls::StateConnectionId connectionId{};
      ls::StateId stateId{};

      void _assignConnectionId(const ls::StateConnectionId& _connectionId);
      void _assignStateId(const ls::StateId& _stateId);
  };
}

#endif
