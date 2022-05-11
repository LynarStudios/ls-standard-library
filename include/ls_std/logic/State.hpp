/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/core/Class.hpp>
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"
#include <ls_std/core/interface/ISerializable.hpp>

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class State : public ls::std::core::Class
      {
        public:

          explicit State(const ls::std::logic::StateId &_id);
          ~State() override = default;

          // additional functionality

          bool addStateConnection(const ls::std::logic::StateConnectionId &_connectionId, const ::std::shared_ptr<ls::std::logic::State> &_connectedState);
          bool addStateConnection(const ::std::shared_ptr<ls::std::logic::StateConnection> &_connection);
          void clearConnections();
          ::std::unordered_map<ls::std::logic::StateConnectionId, ::std::shared_ptr<ls::std::logic::StateConnection>> getConnectedStates();
          ls::std::logic::StateId getId();
          bool hasConnection(const ls::std::logic::StateConnectionId &_connectionId);
          void setId(const ls::std::logic::StateId &_id);

        private:

          ::std::unordered_map<ls::std::logic::StateConnectionId, ::std::shared_ptr<ls::std::logic::StateConnection>> connectedStates{};
          ls::std::logic::StateId id{};

          void _assignStateId(const ls::std::logic::StateId &_id);
          void _clearConnections();
          bool _hasConnection(const ls::std::logic::StateConnectionId &_connectionId);
      };
    }
  }
}

#endif
