/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/logic/StateMachine.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::StateMachine::StateMachine(const ::std::string& _name) : ls::std::core::Class("StateMachine")
{
  this->_assignName(_name);
}

bool ls::StateMachine::addState(const ::std::shared_ptr<ls::State> &_state)
{
  bool wasAdded{};

  if (_state == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
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

std::shared_ptr<ls::State> ls::StateMachine::getCurrentState()
{
  return this->currentState;
}

std::vector<ls::StateId> ls::StateMachine::getMemory()
{
  return this->memory;
}

std::string ls::StateMachine::getName()
{
  return this->name;
}

std::unordered_map<ls::StateId, std::shared_ptr<ls::State>> ls::StateMachine::getStates()
{
  return this->states;
}

bool ls::StateMachine::hasState(const ls::StateId &_id)
{
  return this->_hasState(_id);
}

bool ls::StateMachine::proceed()
{
  ::std::vector<ls::StateId> nextValidStates = this->_getNextValidStates();
  bool onlyOneWayToGo = nextValidStates.size() == 1;

  if (onlyOneWayToGo)
  {
    this->currentState = this->states[nextValidStates.at(0)];
    this->_remember(nextValidStates.at(0));
  }

  return onlyOneWayToGo;
}

void ls::StateMachine::setMemory(const ::std::vector<ls::StateId>& _memory)
{
  this->_assignMemory(_memory);
}

void ls::StateMachine::setName(const ::std::string& _name)
{
  this->_assignName(_name);
}

bool ls::StateMachine::setStartState(const ls::StateId &_id)
{
  bool startStateSet{};

  if (_id.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
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

void ls::StateMachine::_assignMemory(const ::std::vector<ls::StateId> &_memory)
{
  if (_memory.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->memory = _memory;
}

void ls::StateMachine::_assignName(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->name = _name;
}

std::vector<ls::StateId> ls::StateMachine::_getNextValidStates()
{
  ::std::vector<ls::StateId> validStates{};

  for (const auto &state : this->currentState->getConnectedStates())
  {
    if (state.second->isPassable())
    {
      validStates.push_back(state.second->getStateId());
    }
  }

  return validStates;
}

void ls::StateMachine::_remember(const ls::StateId &_id)
{
  this->memory.push_back(_id);
}

bool ls::StateMachine::_hasState(const ls::StateId &_id)
{
  return this->states.find(_id) != this->states.end();
}
