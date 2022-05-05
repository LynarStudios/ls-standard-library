/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/logic/State.hpp>
#include <ls_std/core/exception/NullPointerException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::State::State(const ls::StateId& _id) : ls::Class("State")
{
  this->_assignStateId(_id);
}

bool ls::State::addStateConnection(const ls::StateConnectionId &_connectionId, const std::shared_ptr<ls::State> &_connectedState)
{
  bool added{};
  std::shared_ptr<ls::StateConnection> connection{};

  if (_connectionId.empty() || _connectedState == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }
  else
  {
    if (!this->_hasConnection(_connectionId))
    {
      connection = std::make_shared<ls::StateConnection>(_connectionId, _connectedState->getId());
      added = this->connectedStates.insert({_connectionId, connection}).second;
    }
  }

  return added;
}

bool ls::State::addStateConnection(const std::shared_ptr<ls::StateConnection> &_connection)
{
  bool added{};

  if (_connection != nullptr)
  {
    added = this->connectedStates.insert({_connection->getConnectionId(), _connection}).second;
  }
  else
  {
    throw ls::IllegalArgumentException{};
  }

  return added;
}

void ls::State::clearConnections()
{
  this->_clearConnections();
}

std::unordered_map<ls::StateConnectionId, std::shared_ptr<ls::StateConnection>> ls::State::getConnectedStates()
{
  return this->connectedStates;
}

ls::StateId ls::State::getId()
{
  return this->id;
}

bool ls::State::hasConnection(const ls::StateConnectionId &_connectionId)
{
  return this->_hasConnection(_connectionId);
}

void ls::State::setId(const ls::StateId& _id)
{
  this->_assignStateId(_id);
}

void ls::State::_assignStateId(const ls::StateId &_id)
{
  if (_id.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->id = _id;
}

void ls::State::_clearConnections()
{
  this->connectedStates.clear();
}

bool ls::State::_hasConnection(const ls::StateConnectionId &_connectionId)
{
  return this->connectedStates.find(_connectionId) != this->connectedStates.end();
}
