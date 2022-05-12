/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/core/Class.hpp>
#include "ls_std/core/types/StateMachineTypes.hpp"
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

          explicit State(const ls::std::core::type::state_id &_id);
          ~State() override = default;

          // additional functionality

          bool addStateConnection(const ls::std::core::type::state_connection_id &_connectionId, const ::std::shared_ptr<ls::std::logic::State> &_connectedState);
          bool addStateConnection(const ::std::shared_ptr<ls::std::logic::StateConnection> &_connection);
          void clearConnections();
          ::std::unordered_map<ls::std::core::type::state_connection_id, ::std::shared_ptr<ls::std::logic::StateConnection>> getConnectedStates();
          ls::std::core::type::state_id getId();
          bool hasConnection(const ls::std::core::type::state_connection_id &_connectionId);
          void setId(const ls::std::core::type::state_id &_id);

        private:

          ::std::unordered_map<ls::std::core::type::state_connection_id, ::std::shared_ptr<ls::std::logic::StateConnection>> connectedStates{};
          ls::std::core::type::state_id id{};

          void _assignStateId(const ls::std::core::type::state_id &_id);
          void _clearConnections();
          bool _hasConnection(const ls::std::core::type::state_connection_id &_connectionId);
      };
    }
  }
}

#endif
