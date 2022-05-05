/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-05
 *
 * */

#include "ls_std/logic/serialization/SerializableJsonState.hpp"
#include "ls_std/logic/serialization/SerializableJsonStateConnection.hpp"
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::SerializableJsonState::SerializableJsonState(const std::shared_ptr<ls::State> &_value) : ls::Class("SerializableJsonState")
{
  this->_assignValue(_value);
}

ls::byte_field ls::SerializableJsonState::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::SerializableJsonState::unmarshal(const ls::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStateConnections();
  this->value->setId(this->jsonObject["id"]);
}

std::shared_ptr<ls::State> ls::SerializableJsonState::getValue()
{
  return this->value;
}

void ls::SerializableJsonState::setValue(const std::shared_ptr<ls::State> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls::SerializableJsonState::_assignValue(const std::shared_ptr<ls::State> &_value)
{
  if (_value == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::SerializableJsonState::_clear()
{
  this->jsonObject.clear();
}

void ls::SerializableJsonState::_unmarshalStateConnections()
{
  if (!this->jsonObject["connectedStates"].empty())
  {
    this->value->clearConnections();

    for (const auto &connectionJson : this->jsonObject["connectedStates"])
    {
      std::shared_ptr<ls::StateConnection> connection = std::make_shared<ls::StateConnection>("TMP_ID", "TMP_ID");
      ls::SerializableJsonStateConnection{connection}.unmarshal(connectionJson.dump());
      this->value->addStateConnection(connection);
    }
  }
}

void ls::SerializableJsonState::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateStateConnections();
}

void ls::SerializableJsonState::_updateStateConnections()
{
  std::string jsonString{};

  for (const auto &connection : this->value->getConnectedStates())
  {
    jsonString = ls::SerializableJsonStateConnection{connection.second}.marshal();
    this->jsonObject["connectedStates"][connection.first] = nlohmann::json::parse(jsonString);
  }
}
