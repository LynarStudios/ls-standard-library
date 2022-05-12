/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/logic/StateConnection.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::StateConnection::StateConnection(const ls::std::core::type::state_connection_id& _connectionId, const ls::std::core::type::state_id& _stateId) : ls::std::core::Class("StateConnection")
{
  this->_assignConnectionId(_connectionId);
  this->_assignStateId(_stateId);
}

ls::std::core::type::state_connection_id ls::std::logic::StateConnection::getConnectionId()
{
  return this->connectionId;
}

ls::std::core::type::state_id ls::std::logic::StateConnection::getStateId()
{
  return this->stateId;
}

bool ls::std::logic::StateConnection::isPassable() const
{
  return this->condition;
}

void ls::std::logic::StateConnection::setConnectionId(const ls::std::core::type::state_connection_id& _connectionId)
{
  this->_assignConnectionId(_connectionId);
}

void ls::std::logic::StateConnection::setStateId(const ls::std::core::type::state_id& _stateId)
{
  this->_assignStateId(_stateId);
}

void ls::std::logic::StateConnection::updatePassCondition(bool _condition)
{
  this->condition = _condition;
}

void ls::std::logic::StateConnection::_assignConnectionId(const ls::std::core::type::state_connection_id &_connectionId)
{
  if (_connectionId.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->connectionId = _connectionId;
}

void ls::std::logic::StateConnection::_assignStateId(const ls::std::core::type::state_id &_stateId)
{
  if (_stateId.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->stateId = _stateId;
}
