/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2020-11-06
 *
 * */

#include "../../../../../include/ls_std/serialization/logic/SerializableJSONStateConnection.hpp"

ls_std::SerializableJSONStateConnection::SerializableJSONStateConnection(std::shared_ptr<ls_std::StateConnection> _value) :
Class("SerializableJSONStateConnection"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONStateConnection::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONStateConnection::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  this->value->setConnectionId(this->jsonObject["connectionId"]);
  this->value->setStateId(this->jsonObject["stateId"]);
  this->value->updatePassCondition(this->jsonObject["condition"]);
}

void ls_std::SerializableJSONStateConnection::setValue(std::shared_ptr<ls_std::StateConnection> _value)
{
  this->value = std::move(_value);
  this->_clear();
}

void ls_std::SerializableJSONStateConnection::_clear()
{
  this->jsonObject.clear();
}

void ls_std::SerializableJSONStateConnection::_update()
{
  this->jsonObject = {
      {"condition", this->value->isPassable()},
      {"connectionId", this->value->getConnectionId()},
      {"stateId", this->value->getStateId()}
  };
}
