/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-05
 *
 * */

#include "State.hpp"

ls_std::State::State(std::string  _id) : Class("State"),
id(std::move(_id))
{}

bool ls_std::State::addStateConnection(const std::shared_ptr<State>& _connectedState)
{
  bool added {};

  if(_connectedState != nullptr && !this->_stateIsConnected(_connectedState->getId())) {
    this->connectedStates.emplace_back(_connectedState);
    added = true;
  }

  return added;
}

std::list<std::shared_ptr<ls_std::State>> ls_std::State::getConnectedStates()
{
  return this->connectedStates;
}

std::string ls_std::State::getId()
{
  return this->id;
}

bool ls_std::State::isAccessible() const
{
  return this->accessCondition;
}

void ls_std::State::removeStateConnection(const std::string &_id)
{
  auto iterator = this->connectedStates.begin();

  while(iterator != this->connectedStates.end()) {
    if(iterator->get()->getId() == _id) {
      this->connectedStates.erase(iterator);
      break;
    }

    iterator++;
  }
}

void ls_std::State::updateAccessCondition(bool _enteredCondition)
{
  this->accessCondition = _enteredCondition;
}

bool ls_std::State::_stateIsConnected(const std::string &_id)
{
  bool connected {};

  for(const std::shared_ptr<State>& state : this->connectedStates) {
    connected = state->getId() == _id;

    if(connected) {
      break;
    }
  }

  return connected;
}
