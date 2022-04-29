/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "StateMachineTypes.hpp"

namespace ls_std
{
  class StateConnection : public ls_std::Class
  {
    public:

      explicit StateConnection(const ls_std::StateConnectionId& _connectionId, const ls_std::StateId& _stateId);
      ~StateConnection() override = default;

      StateConnectionId getConnectionId();
      ls_std::StateId getStateId();
      bool isPassable() const;
      void setConnectionId(const ls_std::StateConnectionId& _connectionId);
      void setStateId(const ls_std::StateId& _stateId);
      void updatePassCondition(bool _condition);

    private:

      bool condition{};
      ls_std::StateConnectionId connectionId{};
      ls_std::StateId stateId{};

      void _assignConnectionId(const ls_std::StateConnectionId& _connectionId);
      void _assignStateId(const ls_std::StateId& _stateId);
  };
}

#endif
