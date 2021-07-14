/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2021-07-14
 *
 * */

#include <ls_std/logic/State.hpp>
#include <ls_std/exception/NullPointerException.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::State::State(const ls_std::StateId& _id) : ls_std::Class("State")
{
  this->_assignStateId(_id);
}

bool ls_std::State::addStateConnection(const ls_std::StateConnectionId &_connectionId, const std::shared_ptr<ls_std::State> &_connectedState)
{
  bool added{};
  std::shared_ptr<ls_std::StateConnection> connection{};

  if (_connectionId.empty() || _connectedState == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
  else
  {
    if (!this->_hasConnection(_connectionId))
    {
      connection = std::make_shared<ls_std::StateConnection>(_connectionId, _connectedState->getId());
      added = this->connectedStates.insert({_connectionId, connection}).second;
    }
  }

  return added;
}

bool ls_std::State::addStateConnection(const std::shared_ptr<ls_std::StateConnection> &_connection)
{
  bool added{};

  if (_connection != nullptr)
  {
    added = this->connectedStates.insert({_connection->getConnectionId(), _connection}).second;
  }
  else
  {
    throw ls_std::IllegalArgumentException{};
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

bool ls_std::State::hasConnection(const ls_std::StateConnectionId &_connectionId)
{
  return this->_hasConnection(_connectionId);
}

void ls_std::State::setId(const ls_std::StateId& _id)
{
  this->_assignStateId(_id);
}

void ls_std::State::_assignStateId(const ls_std::StateId &_id)
{
  if (_id.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->id = _id;
}

void ls_std::State::_clearConnections()
{
  this->connectedStates.clear();
}

bool ls_std::State::_hasConnection(const ls_std::StateConnectionId &_connectionId)
{
  return this->connectedStates.find(_connectionId) != this->connectedStates.end();
}
