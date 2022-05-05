/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/logic/StateConnection.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::StateConnection::StateConnection(const ls::StateConnectionId& _connectionId, const ls::StateId& _stateId) : ls::Class("StateConnection")
{
  this->_assignConnectionId(_connectionId);
  this->_assignStateId(_stateId);
}

ls::StateConnectionId ls::StateConnection::getConnectionId()
{
  return this->connectionId;
}

ls::StateId ls::StateConnection::getStateId()
{
  return this->stateId;
}

bool ls::StateConnection::isPassable() const
{
  return this->condition;
}

void ls::StateConnection::setConnectionId(const ls::StateConnectionId& _connectionId)
{
  this->_assignConnectionId(_connectionId);
}

void ls::StateConnection::setStateId(const ls::StateId& _stateId)
{
  this->_assignStateId(_stateId);
}

void ls::StateConnection::updatePassCondition(bool _condition)
{
  this->condition = _condition;
}

void ls::StateConnection::_assignConnectionId(const ls::StateConnectionId &_connectionId)
{
  if (_connectionId.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->connectionId = _connectionId;
}

void ls::StateConnection::_assignStateId(const ls::StateId &_stateId)
{
  if (_stateId.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->stateId = _stateId;
}
