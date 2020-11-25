/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2020-11-25
 *
 * */

#include <ls_std/serialization/logic/SerializableJSONState.hpp>
#include <ls_std/serialization/logic/SerializableJSONStateConnection.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJSONState::SerializableJSONState(const std::shared_ptr<State>& _value) :
Class("SerializableJSONState")
{
  this->_assignValue(_value);
}

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

void ls_std::SerializableJSONState::setValue(const std::shared_ptr<State>& _value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls_std::SerializableJSONState::_assignValue(const std::shared_ptr<State> &_value)
{
  if(_value == nullptr) {
    throw ls_std::IllegalArgumentException {};
  }

  this->value = _value;
}

void ls_std::SerializableJSONState::_clear()
{
  this->jsonObject.clear();
}

void ls_std::SerializableJSONState::_unmarshalStateConnections()
{
  if(!this->jsonObject["connectedStates"].empty()) {
    this->value->clearConnections();

    for(const auto& connectionJSON : this->jsonObject["connectedStates"]) {
      std::shared_ptr<ls_std::StateConnection> connection = std::make_shared<ls_std::StateConnection>("TMP_ID", "TMP_ID");
      ls_std::SerializableJSONStateConnection{connection}.unmarshal(connectionJSON.dump());
      this->value->addStateConnection(connection);
    }
  }
}

void ls_std::SerializableJSONState::_update()
{
  this->jsonObject = {
      {"id", this->value->getId()}
  };

  this->_updateStateConnections();
}

void ls_std::SerializableJSONState::_updateStateConnections()
{
  std::string jsonString {};

  for(const auto& connection : this->value->getConnectedStates()) {
    jsonString = ls_std::SerializableJSONStateConnection{connection.second}.marshal();
    this->jsonObject["connectedStates"][connection.first] = nlohmann::json::parse(jsonString);
  }
}
