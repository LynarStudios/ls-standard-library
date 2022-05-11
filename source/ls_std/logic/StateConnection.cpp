/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/logic/StateConnection.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::StateConnection::StateConnection(const ls::std::logic::StateConnectionId& _connectionId, const ls::std::logic::StateId& _stateId) : ls::std::core::Class("StateConnection")
{
  this->_assignConnectionId(_connectionId);
  this->_assignStateId(_stateId);
}

ls::std::logic::StateConnectionId ls::std::logic::StateConnection::getConnectionId()
{
  return this->connectionId;
}

ls::std::logic::StateId ls::std::logic::StateConnection::getStateId()
{
  return this->stateId;
}

bool ls::std::logic::StateConnection::isPassable() const
{
  return this->condition;
}

void ls::std::logic::StateConnection::setConnectionId(const ls::std::logic::StateConnectionId& _connectionId)
{
  this->_assignConnectionId(_connectionId);
}

void ls::std::logic::StateConnection::setStateId(const ls::std::logic::StateId& _stateId)
{
  this->_assignStateId(_stateId);
}

void ls::std::logic::StateConnection::updatePassCondition(bool _condition)
{
  this->condition = _condition;
}

void ls::std::logic::StateConnection::_assignConnectionId(const ls::std::logic::StateConnectionId &_connectionId)
{
  if (_connectionId.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->connectionId = _connectionId;
}

void ls::std::logic::StateConnection::_assignStateId(const ls::std::logic::StateId &_stateId)
{
  if (_stateId.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->stateId = _stateId;
}
