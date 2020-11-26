/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/logic/StateMachine.hpp>

ls_std::StateMachine::StateMachine(std::string _name) :
ls_std::Class("StateMachine"),
name(std::move(_name))
{}

bool ls_std::StateMachine::addState(const std::shared_ptr<ls_std::State>& _state) {
  bool condition = !this->_hasState(_state->getId());

  if(condition) {
    this->states.insert({_state->getId(), _state});
    condition = this->_hasState(_state->getId());
  }

  return condition;
}

std::shared_ptr<ls_std::State> ls_std::StateMachine::getCurrentState() {
  return this->currentState;
}

std::vector<ls_std::StateId> ls_std::StateMachine::getMemory() {
  return this->memory;
}

std::string ls_std::StateMachine::getName() {
  return this->name;
}

std::unordered_map<ls_std::StateId, std::shared_ptr<ls_std::State>> ls_std::StateMachine::getStates()
{
  return this->states;
}

bool ls_std::StateMachine::hasState(const ls_std::StateId &_id)
{
  return this->_hasState(_id);
}

bool ls_std::StateMachine::proceed() {
  std::vector<ls_std::StateId> nextValidStates = this->_getNextValidStates();
  bool condition = nextValidStates.size() == 1;

  if(condition) {
    this->currentState = this->states[nextValidStates.at(0)];
    this->_remember(nextValidStates.at(0));
  }

  return condition;
}

void ls_std::StateMachine::setMemory(std::vector<ls_std::StateId> _memory)
{
  this->memory = std::move(_memory);
}

void ls_std::StateMachine::setName(std::string _name)
{
  this->name = std::move(_name);
}

bool ls_std::StateMachine::setStartState(const ls_std::StateId&_id) {
  bool exists = this->_hasState(_id);

  if(exists) {
    this->currentState = this->states[_id];
    this->_remember(_id);
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

void ls_std::StateMachine::_remember(const ls_std::StateId &_id) {
  this->memory.push_back(_id);
}

bool ls_std::StateMachine::_hasState(const ls_std::StateId &_id) {
  return this->states.find(_id) != this->states.end();
}
