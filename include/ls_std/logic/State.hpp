/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/core/Class.hpp>
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"
#include <ls_std/serialization/ISerializable.hpp>

namespace ls
{
  class State : public ls::Class
  {
    public:

      explicit State(const ls::StateId& _id);
      ~State() override = default;

      // additional functionality

      bool addStateConnection(const ls::StateConnectionId &_connectionId, const ::std::shared_ptr<ls::State> &_connectedState);
      bool addStateConnection(const ::std::shared_ptr<ls::StateConnection> &_connection);
      void clearConnections();
      ::std::unordered_map<ls::StateConnectionId, ::std::shared_ptr<ls::StateConnection>> getConnectedStates();
      ls::StateId getId();
      bool hasConnection(const ls::StateConnectionId &_connectionId);
      void setId(const ls::StateId& _id);

    private:

      ::std::unordered_map<ls::StateConnectionId, ::std::shared_ptr<ls::StateConnection>> connectedStates{};
      ls::StateId id{};

      void _assignStateId(const ls::StateId& _id);
      void _clearConnections();
      bool _hasConnection(const ls::StateConnectionId &_connectionId);
  };
}

#endif
