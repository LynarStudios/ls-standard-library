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

ls_std::StateConnection::StateConnection(const ls_std::StateConnectionId& _connectionId, const ls_std::StateId& _stateId) : ls_std::Class("StateConnection")
{
  this->_assignConnectionId(_connectionId);
  this->_assignStateId(_stateId);
}

ls_std::StateConnectionId ls_std::StateConnection::getConnectionId()
{
  return this->connectionId;
}

ls_std::StateId ls_std::StateConnection::getStateId()
{
  return this->stateId;
}

bool ls_std::StateConnection::isPassable() const
{
  return this->condition;
}

void ls_std::StateConnection::setConnectionId(const ls_std::StateConnectionId& _connectionId)
{
  this->_assignConnectionId(_connectionId);
}

void ls_std::StateConnection::setStateId(const ls_std::StateId& _stateId)
{
  this->_assignStateId(_stateId);
}

void ls_std::StateConnection::updatePassCondition(bool _condition)
{
  this->condition = _condition;
}

void ls_std::StateConnection::_assignConnectionId(const ls_std::StateConnectionId &_connectionId)
{
  if (_connectionId.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->connectionId = _connectionId;
}

void ls_std::StateConnection::_assignStateId(const ls_std::StateId &_stateId)
{
  if (_stateId.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->stateId = _stateId;
}
