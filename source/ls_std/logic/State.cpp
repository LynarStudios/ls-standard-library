/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-10-29
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

  if(_connectedState != nullptr && !this->_hasConnection(_connectionId)) {
    connection = std::make_shared<ls_std::StateConnection>(_connectionId, _connectedState->getId());
    this->connectedStates.insert({_connectionId, connection});
    added = true;
  }

  return added;
}

bool ls_std::State::addStateConnection(const std::shared_ptr<StateConnection>& _connection)
{
  bool added {};

  if(_connection != nullptr) {
    this->connectedStates.insert({_connection->getConnectionId(), _connection});
    added = this->_hasConnection(_connection->getConnectionId());
  }

  return added;
}

void ls_std::State::clearConnections()
{
  this->_clearConnections();
}

std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> ls_std::State::getConnectedStates()
{
  return this->connectedStates;
}

ls_std::StateId ls_std::State::getId()
{
  return this->id;
}

bool ls_std::State::hasConnection(const StateConnectionId &_connectionId)
{
  return this->_hasConnection(_connectionId);
}

void ls_std::State::setId(StateId _id)
{
  this->id = std::move(_id);
}

void ls_std::State::_clearConnections()
{
  this->connectedStates.clear();
}

bool ls_std::State::_hasConnection(const StateConnectionId &_connectionId)
{
  return this->connectedStates.find(_connectionId) != this->connectedStates.end();
}
