/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_STATE_MACHINE_HPP
#define LS_STD_STATE_MACHINE_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include <ls_std/core/Class.hpp>
#include "State.hpp"
#include "StateMachineTypes.hpp"

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class StateMachine : public ls::std::core::Class
      {
        public:

          explicit StateMachine(const ::std::string &_name);
          ~StateMachine() override = default;

          bool addState(const ::std::shared_ptr<ls::std::logic::State> &_state);
          ::std::shared_ptr<ls::std::logic::State> getCurrentState();
          ::std::vector<ls::std::logic::StateId> getMemory();
          ::std::string getName();
          ::std::unordered_map<ls::std::logic::StateId, ::std::shared_ptr<ls::std::logic::State>> getStates();
          bool hasState(const ls::std::logic::StateId &_id);
          bool proceed();
          void setMemory(const ::std::vector<ls::std::logic::StateId> &_memory);
          void setName(const ::std::string &_name);
          bool setStartState(const ls::std::logic::StateId &_id);

        private:

          ::std::shared_ptr<ls::std::logic::State> currentState{};
          ::std::vector<ls::std::logic::StateId> memory{};
          ::std::string name{};
          ::std::unordered_map<ls::std::logic::StateId, ::std::shared_ptr<ls::std::logic::State>> states{};

          void _assignMemory(const ::std::vector<ls::std::logic::StateId> &_memory);
          void _assignName(const ::std::string &_name);
          ::std::vector<ls::std::logic::StateId> _getNextValidStates();
          void _remember(const ls::std::logic::StateId &_id);
          bool _hasState(const ls::std::logic::StateId &_id);
      };
    }
  }
}

#endif
