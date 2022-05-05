/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/logic/StateMachine.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls_std::StateMachine::StateMachine(const std::string& _name) : ls_std::Class("StateMachine")
{
  this->_assignName(_name);
}

bool ls_std::StateMachine::addState(const std::shared_ptr<ls_std::State> &_state)
{
  bool wasAdded{};

  if (_state == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
  else
  {
    if (!this->_hasState(_state->getId()))
    {
      wasAdded = this->states.insert({_state->getId(), _state}).second;
    }
  }

  return wasAdded;
}

std::shared_ptr<ls_std::State> ls_std::StateMachine::getCurrentState()
{
  return this->currentState;
}

std::vector<ls_std::StateId> ls_std::StateMachine::getMemory()
{
  return this->memory;
}

std::string ls_std::StateMachine::getName()
{
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

bool ls_std::StateMachine::proceed()
{
  std::vector<ls_std::StateId> nextValidStates = this->_getNextValidStates();
  bool onlyOneWayToGo = nextValidStates.size() == 1;

  if (onlyOneWayToGo)
  {
    this->currentState = this->states[nextValidStates.at(0)];
    this->_remember(nextValidStates.at(0));
  }

  return onlyOneWayToGo;
}

void ls_std::StateMachine::setMemory(const std::vector<ls_std::StateId>& _memory)
{
  this->_assignMemory(_memory);
}

void ls_std::StateMachine::setName(const std::string& _name)
{
  this->_assignName(_name);
}

bool ls_std::StateMachine::setStartState(const ls_std::StateId &_id)
{
  bool startStateSet{};

  if (_id.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }
  else
  {
    if (this->_hasState(_id))
    {
      this->currentState = this->states[_id];
      this->_remember(_id);
      startStateSet = true;
    }
  }

  return startStateSet;
}

void ls_std::StateMachine::_assignMemory(const std::vector<ls_std::StateId> &_memory)
{
  if (_memory.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->memory = _memory;
}

void ls_std::StateMachine::_assignName(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->name = _name;
}

std::vector<ls_std::StateId> ls_std::StateMachine::_getNextValidStates()
{
  std::vector<ls_std::StateId> validStates{};

  for (const auto &state : this->currentState->getConnectedStates())
  {
    if (state.second->isPassable())
    {
      validStates.push_back(state.second->getStateId());
    }
  }

  return validStates;
}

void ls_std::StateMachine::_remember(const ls_std::StateId &_id)
{
  this->memory.push_back(_id);
}

bool ls_std::StateMachine::_hasState(const ls_std::StateId &_id)
{
  return this->states.find(_id) != this->states.end();
}
