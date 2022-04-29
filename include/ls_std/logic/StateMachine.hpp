/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-04-29
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

namespace ls_std
{
  class StateMachine : public ls_std::Class
  {
    public:

      explicit StateMachine(const std::string& _name);
      ~StateMachine() override = default;

      bool addState(const std::shared_ptr<ls_std::State> &_state);
      std::shared_ptr<ls_std::State> getCurrentState();
      std::vector<ls_std::StateId> getMemory();
      std::string getName();
      std::unordered_map<StateId, std::shared_ptr<ls_std::State>> getStates();
      bool hasState(const ls_std::StateId &_id);
      bool proceed();
      void setMemory(const std::vector<ls_std::StateId>& _memory);
      void setName(const std::string& _name);
      bool setStartState(const ls_std::StateId &_id);

    private:

      std::shared_ptr<State> currentState{};
      std::vector<ls_std::StateId> memory{};
      std::string name{};
      std::unordered_map<ls_std::StateId, std::shared_ptr<ls_std::State>> states{};

      void _assignMemory(const std::vector<ls_std::StateId>& _memory);
      void _assignName(const std::string& _name);
      std::vector<ls_std::StateId> _getNextValidStates();
      void _remember(const ls_std::StateId &_id);
      bool _hasState(const ls_std::StateId &_id);
  };
}

#endif
