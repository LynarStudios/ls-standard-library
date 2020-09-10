/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-09-10
 *
 * */

#include "StateConnection.hpp"

#include <utility>

ls_std::StateConnection::StateConnection(std::string _connectionId, std::shared_ptr<State> _state) :
Class("StateConnection"),
connectionId(std::move(_connectionId)),
state(std::move(_state))
{}

std::string ls_std::StateConnection::getConnectionId() {
  return this->connectionId;
}

std::shared_ptr<ls_std::State> ls_std::StateConnection::getState() {
  return this->state;
}

bool ls_std::StateConnection::isPassable() {
  return this->condition;
}

void ls_std::StateConnection::updatePassCondition(bool _condition) {
  this->condition = _condition;
}
