/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/logic/State.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::State::State(const ls::std::core::type::state_id& _id) : ls::std::core::Class("State")
{
  this->_assignStateId(_id);
}

bool ls::std::logic::State::addStateConnection(const ls::std::core::type::state_connection_id &_connectionId, const ::std::shared_ptr<ls::std::logic::State> &_connectedState)
{
  bool added{};
  ::std::shared_ptr<ls::std::logic::StateConnection> connection{};

  if (_connectionId.empty() || _connectedState == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    if (!this->_hasConnection(_connectionId))
    {
      connection = ::std::make_shared<ls::std::logic::StateConnection>(_connectionId, _connectedState->getId());
      added = this->connectedStates.insert({_connectionId, connection}).second;
    }
  }

  return added;
}

bool ls::std::logic::State::addStateConnection(const ::std::shared_ptr<ls::std::logic::StateConnection> &_connection)
{
  bool added;

  if (_connection != nullptr)
  {
    added = this->connectedStates.insert({_connection->getConnectionId(), _connection}).second;
  }
  else
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  return added;
}

void ls::std::logic::State::clearConnections()
{
  this->_clearConnections();
}

std::unordered_map<ls::std::core::type::state_connection_id, std::shared_ptr<ls::std::logic::StateConnection>> ls::std::logic::State::getConnectedStates()
{
  return this->connectedStates;
}

ls::std::core::type::state_id ls::std::logic::State::getId()
{
  return this->id;
}

bool ls::std::logic::State::hasConnection(const ls::std::core::type::state_connection_id &_connectionId)
{
  return this->_hasConnection(_connectionId);
}

void ls::std::logic::State::setId(const ls::std::core::type::state_id& _id)
{
  this->_assignStateId(_id);
}

void ls::std::logic::State::_assignStateId(const ls::std::core::type::state_id &_id)
{
  if (_id.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->id = _id;
}

void ls::std::logic::State::_clearConnections()
{
  this->connectedStates.clear();
}

bool ls::std::logic::State::_hasConnection(const ls::std::core::type::state_connection_id &_connectionId)
{
  return this->connectedStates.find(_connectionId) != this->connectedStates.end();
}
