/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-05-05
 *
 * */

#include "ls_std/logic/serialization/SerializableJsonStateConnection.hpp"
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::SerializableJsonStateConnection::SerializableJsonStateConnection(const std::shared_ptr<ls::StateConnection> &_value) : ls::Class("SerializableJsonStateConnection")
{
  this->_assignValue(_value);
}

ls::byte_field ls::SerializableJsonStateConnection::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::SerializableJsonStateConnection::unmarshal(const ls::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  this->value->setConnectionId(this->jsonObject["connectionId"]);
  this->value->setStateId(this->jsonObject["stateId"]);
  this->value->updatePassCondition(this->jsonObject["condition"]);
}

std::shared_ptr<ls::StateConnection> ls::SerializableJsonStateConnection::getValue()
{
  return this->value;
}

void ls::SerializableJsonStateConnection::setValue(const std::shared_ptr<ls::StateConnection> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls::SerializableJsonStateConnection::_assignValue(const std::shared_ptr<ls::StateConnection> &_value)
{
  if (_value == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::SerializableJsonStateConnection::_clear()
{
  this->jsonObject.clear();
}

void ls::SerializableJsonStateConnection::_update()
{
  this->jsonObject = {{"condition",    this->value->isPassable()},
                      {"connectionId", this->value->getConnectionId()},
                      {"stateId",      this->value->getStateId()}};
}
