/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/logic/StateMachine.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::StateMachine::StateMachine(const ::std::string& _name) : ls::std::core::Class("StateMachine")
{
  this->_assignName(_name);
}

bool ls::std::logic::StateMachine::addState(const ::std::shared_ptr<ls::std::logic::State> &_state)
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

std::shared_ptr<ls::std::logic::State> ls::std::logic::StateMachine::getCurrentState()
{
  return this->currentState;
}

std::vector<ls::std::logic::StateId> ls::std::logic::StateMachine::getMemory()
{
  return this->memory;
}

std::string ls::std::logic::StateMachine::getName()
{
  return this->name;
}

std::unordered_map<ls::std::logic::StateId, std::shared_ptr<ls::std::logic::State>> ls::std::logic::StateMachine::getStates()
{
  return this->states;
}

bool ls::std::logic::StateMachine::hasState(const ls::std::logic::StateId &_id)
{
  return this->_hasState(_id);
}

bool ls::std::logic::StateMachine::proceed()
{
  ::std::vector<ls::std::logic::StateId> nextValidStates = this->_getNextValidStates();
  bool onlyOneWayToGo = nextValidStates.size() == 1;

  if (onlyOneWayToGo)
  {
    this->currentState = this->states[nextValidStates.at(0)];
    this->_remember(nextValidStates.at(0));
  }

  return onlyOneWayToGo;
}

void ls::std::logic::StateMachine::setMemory(const ::std::vector<ls::std::logic::StateId>& _memory)
{
  this->_assignMemory(_memory);
}

void ls::std::logic::StateMachine::setName(const ::std::string& _name)
{
  this->_assignName(_name);
}

bool ls::std::logic::StateMachine::setStartState(const ls::std::logic::StateId &_id)
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

void ls::std::logic::StateMachine::_assignMemory(const ::std::vector<ls::std::logic::StateId> &_memory)
{
  if (_memory.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->memory = _memory;
}

void ls::std::logic::StateMachine::_assignName(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->name = _name;
}

std::vector<ls::std::logic::StateId> ls::std::logic::StateMachine::_getNextValidStates()
{
  ::std::vector<ls::std::logic::StateId> validStates{};

  for (const auto &state : this->currentState->getConnectedStates())
  {
    if (state.second->isPassable())
    {
      validStates.push_back(state.second->getStateId());
    }
  }

  return validStates;
}

void ls::std::logic::StateMachine::_remember(const ls::std::logic::StateId &_id)
{
  this->memory.push_back(_id);
}

bool ls::std::logic::StateMachine::_hasState(const ls::std::logic::StateId &_id)
{
  return this->states.find(_id) != this->states.end();
}
