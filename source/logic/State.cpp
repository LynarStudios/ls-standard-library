/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#include "State.hpp"

ls_std::State::State(ls_std::StateId _id) : Class("State"),
id(std::move(_id))
{}

bool ls_std::State::addStateConnection(const StateConnectionId& _connectionId, const std::shared_ptr<State>& _connectedState)
{
  bool added {};
  std::shared_ptr<ls_std::StateConnection> connection {};

  if(_connectedState != nullptr && !this->_stateIsConnected(_connectionId)) {
    connection = std::make_shared<ls_std::StateConnection>(_connectionId, _connectedState->getId());
    this->connectedStates.insert({_connectionId, connection});
    added = true;
  }

  return added;
}

std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> ls_std::State::getConnectedStates()
{
  return this->connectedStates;
}

ls_std::StateId ls_std::State::getId()
{
  return this->id;
}

bool ls_std::State::_stateIsConnected(const std::string &_id)
{
  return this->connectedStates.find(_id) != this->connectedStates.end();
}
