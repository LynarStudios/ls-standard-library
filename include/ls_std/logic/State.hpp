/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2021-07-14
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/base/Class.hpp>
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"
#include <ls_std/serialization/ISerializable.hpp>

namespace ls_std
{
  class State : public ls_std::Class
  {
    public:

      explicit State(const ls_std::StateId& _id);
      ~State() override = default;

      // additional functionality

      bool addStateConnection(const ls_std::StateConnectionId &_connectionId, const std::shared_ptr<ls_std::State> &_connectedState);
      bool addStateConnection(const std::shared_ptr<ls_std::StateConnection> &_connection);
      void clearConnections();
      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> getConnectedStates();
      ls_std::StateId getId();
      bool hasConnection(const ls_std::StateConnectionId &_connectionId);
      void setId(const ls_std::StateId& _id);

    private:

      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> connectedStates{};
      ls_std::StateId id{};

      void _assignStateId(const ls_std::StateId& _id);
      void _clearConnections();
      bool _hasConnection(const ls_std::StateConnectionId &_connectionId);
  };
}

#endif
