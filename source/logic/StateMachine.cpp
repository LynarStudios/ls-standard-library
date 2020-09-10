/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#include "StateMachine.hpp"

ls_std::StateMachine::StateMachine(std::string _name) :
Class("StateMachine"),
name(std::move(_name))
{}

bool ls_std::StateMachine::addState(const std::shared_ptr<State>& _state) {
  bool condition = !this->_stateExists(_state->getId());

  if(condition) {
    this->states.insert({_state->getId(), _state});
    condition = this->_stateExists(_state->getId());
  }

  return condition;
}

std::shared_ptr<ls_std::State> ls_std::StateMachine::getCurrentState() {
  return this->currentState;
}

std::string ls_std::StateMachine::getName() {
  return this->name;
}

bool ls_std::StateMachine::proceed() {
  std::vector<ls_std::StateId> nextValidStates = this->_getNextValidStates();
  bool condition = nextValidStates.size() == 1;

  if(condition) {
    this->currentState = this->states[nextValidStates.at(0)];
  }

  return condition;
}

bool ls_std::StateMachine::setStartState(const ls_std::StateId&_id) {
  bool exists = this->_stateExists(_id);

  if(exists) {
    this->currentState = this->states[_id];
  }

  return exists;
}

std::vector<ls_std::StateId> ls_std::StateMachine::_getNextValidStates() {
  std::vector<ls_std::StateId> validStates {};

  for(const auto& state : this->currentState->getConnectedStates()) {
    if(state.second->isPassable()) {
      validStates.push_back(state.second->getStateId());
    }
  }

  return validStates;
}

bool ls_std::StateMachine::_stateExists(const ls_std::StateId &_id) {
  return this->states.find(_id) != this->states.end();
}
