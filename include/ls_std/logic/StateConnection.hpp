/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "StateMachineTypes.hpp"

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class StateConnection : public ls::std::core::Class
      {
        public:

          explicit StateConnection(const ls::std::logic::StateConnectionId &_connectionId, const ls::std::logic::StateId &_stateId);
          ~StateConnection() override = default;

          StateConnectionId getConnectionId();
          ls::std::logic::StateId getStateId();
          bool isPassable() const;
          void setConnectionId(const ls::std::logic::StateConnectionId &_connectionId);
          void setStateId(const ls::std::logic::StateId &_stateId);
          void updatePassCondition(bool _condition);

        private:

          bool condition{};
          ls::std::logic::StateConnectionId connectionId{};
          ls::std::logic::StateId stateId{};

          void _assignConnectionId(const ls::std::logic::StateConnectionId &_connectionId);
          void _assignStateId(const ls::std::logic::StateId &_stateId);
      };
    }
  }
}

#endif
