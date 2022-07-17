/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-07-15
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include <ls_std/core/types/StateMachineTypes.hpp>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::logic
{
  class [[deprecated("consider using ls_game_tool_kit dependency instead!")]] LS_STD_DYNAMIC_GOAL StateConnection : public ls::std::core::Class
  {
    public:

      explicit StateConnection(const ls::std::core::type::state_connection_id &_connectionId, const ls::std::core::type::state_id &_stateId);
      ~StateConnection() override = default;

      ls::std::core::type::state_connection_id getConnectionId();
      ls::std::core::type::state_id getStateId();
      [[nodiscard]] bool isPassable() const;
      void setConnectionId(const ls::std::core::type::state_connection_id &_connectionId);
      void setStateId(const ls::std::core::type::state_id &_stateId);
      void updatePassCondition(bool _condition);

    private:

      bool condition{};
      ls::std::core::type::state_connection_id connectionId{};
      ls::std::core::type::state_id stateId{};

      void _assignConnectionId(const ls::std::core::type::state_connection_id &_connectionId);
      void _assignStateId(const ls::std::core::type::state_id &_stateId);
  };
}

#endif
