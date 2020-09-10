/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#include "State.hpp"

ls_std::State::State(std::string  _id) : Class("State"),
id(std::move(_id))
{}

bool ls_std::State::addStateConnection(const std::string& _connectionId, const std::shared_ptr<State>& _connectedState)
{
  bool added {};

  if(_connectedState != nullptr && !this->_stateIsConnected(_connectionId)) {
    this->connectedStates.insert({_connectionId, _connectedState});
    added = true;
  }

  return added;
}

std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::State>> ls_std::State::getConnectedStates()
{
  return this->connectedStates;
}

std::string ls_std::State::getId()
{
  return this->id;
}

bool ls_std::State::_stateIsConnected(const std::string &_id)
{
  return this->connectedStates.find(_id) != this->connectedStates.end();
}
