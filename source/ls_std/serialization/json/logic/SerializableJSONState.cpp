/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2020-10-29
 *
 * */

#include "SerializableJSONState.hpp"
#include "SerializableJSONStateConnection.hpp"

ls_std::SerializableJSONState::SerializableJSONState(std::shared_ptr<State> _value) :
Class("SerializableJSONState"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONState::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONState::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStateConnections();
  this->value->setId(this->jsonObject["id"]);
}

void ls_std::SerializableJSONState::setValue(std::shared_ptr<State> _value)
{
  this->value = std::move(_value);
  this->_clear();
}

void ls_std::SerializableJSONState::_clear()
{
  this->jsonObject.clear();
}

void ls_std::SerializableJSONState::_unmarshalExistingStateConnection(nlohmann::json _jsonObject)
{
  std::shared_ptr<ls_std::StateConnection> stateConnection = this->value->getConnectedStates().at(_jsonObject["connectionId"]);

  stateConnection->updatePassCondition(_jsonObject["condition"]);
  stateConnection->setStateId(_jsonObject["stateId"]);
}

void ls_std::SerializableJSONState::_unmarshalNewStateConnection(nlohmann::json _jsonObject)
{
  ls_std::StateConnectionId connectionId = _jsonObject["connectionId"];
  ls_std::StateId stateId = _jsonObject["stateId"];
  std::shared_ptr<ls_std::StateConnection> stateConnection = std::make_shared<ls_std::StateConnection>(connectionId, stateId);
  stateConnection->updatePassCondition(_jsonObject["condition"]);

  this->value->addStateConnection(stateConnection);
}

void ls_std::SerializableJSONState::_unmarshalStateConnections()
{
  for(const auto& connectedState : this->jsonObject["connectedStates"]) {
    if(this->value->hasConnection(connectedState["connectionId"])) {
      this->_unmarshalExistingStateConnection(connectedState);
    }
    else {
      this->_unmarshalNewStateConnection(connectedState);
    }
  }
}

void ls_std::SerializableJSONState::_update()
{
  this->_updateStateConnections();
  this->jsonObject["id"] = this->value->getId();
}

void ls_std::SerializableJSONState::_updateStateConnections()
{
  std::string jsonString {};

  for(const auto& connection : this->value->getConnectedStates()) {
    jsonString = ls_std::SerializableJSONStateConnection{connection.second}.marshal();
    this->jsonObject["connectedStates"][connection.first] = nlohmann::json::parse(jsonString);
  }
}
