/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-09-10
 *
 * */

#include "StateConnection.hpp"

ls_std::StateConnection::StateConnection(ls_std::StateConnectionId _connectionId, ls_std::StateId _stateId) :
Class("StateConnection"),
connectionId(std::move(_connectionId)),
stateId(std::move(_stateId))
{}

ls_std::StateConnectionId ls_std::StateConnection::getConnectionId() {
  return this->connectionId;
}

ls_std::StateId ls_std::StateConnection::getState() {
  return this->stateId;
}

bool ls_std::StateConnection::isPassable() {
  return this->condition;
}

void ls_std::StateConnection::updatePassCondition(bool _condition) {
  this->condition = _condition;
}
