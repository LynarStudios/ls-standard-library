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

ls_std::SerializableJsonStateConnection::SerializableJsonStateConnection(const std::shared_ptr<ls_std::StateConnection> &_value) : ls_std::Class("SerializableJsonStateConnection")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonStateConnection::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonStateConnection::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  this->value->setConnectionId(this->jsonObject["connectionId"]);
  this->value->setStateId(this->jsonObject["stateId"]);
  this->value->updatePassCondition(this->jsonObject["condition"]);
}

std::shared_ptr<ls_std::StateConnection> ls_std::SerializableJsonStateConnection::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonStateConnection::setValue(const std::shared_ptr<ls_std::StateConnection> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls_std::SerializableJsonStateConnection::_assignValue(const std::shared_ptr<ls_std::StateConnection> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonStateConnection::_clear()
{
  this->jsonObject.clear();
}

void ls_std::SerializableJsonStateConnection::_update()
{
  this->jsonObject = {{"condition",    this->value->isPassable()},
                      {"connectionId", this->value->getConnectionId()},
                      {"stateId",      this->value->getStateId()}};
}
