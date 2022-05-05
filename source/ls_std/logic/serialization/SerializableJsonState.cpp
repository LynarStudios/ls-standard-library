/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/serialization/json/logic/SerializableJsonState.hpp>
#include <ls_std/serialization/json/logic/SerializableJsonStateConnection.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonState::SerializableJsonState(const std::shared_ptr<ls_std::State> &_value) : ls_std::Class("SerializableJsonState")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonState::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonState::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStateConnections();
  this->value->setId(this->jsonObject["id"]);
}

std::shared_ptr<ls_std::State> ls_std::SerializableJsonState::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonState::setValue(const std::shared_ptr<ls_std::State> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls_std::SerializableJsonState::_assignValue(const std::shared_ptr<ls_std::State> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonState::_clear()
{
  this->jsonObject.clear();
}

void ls_std::SerializableJsonState::_unmarshalStateConnections()
{
  if (!this->jsonObject["connectedStates"].empty())
  {
    this->value->clearConnections();

    for (const auto &connectionJson : this->jsonObject["connectedStates"])
    {
      std::shared_ptr<ls_std::StateConnection> connection = std::make_shared<ls_std::StateConnection>("TMP_ID", "TMP_ID");
      ls_std::SerializableJsonStateConnection{connection}.unmarshal(connectionJson.dump());
      this->value->addStateConnection(connection);
    }
  }
}

void ls_std::SerializableJsonState::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateStateConnections();
}

void ls_std::SerializableJsonState::_updateStateConnections()
{
  std::string jsonString{};

  for (const auto &connection : this->value->getConnectedStates())
  {
    jsonString = ls_std::SerializableJsonStateConnection{connection.second}.marshal();
    this->jsonObject["connectedStates"][connection.first] = nlohmann::json::parse(jsonString);
  }
}
