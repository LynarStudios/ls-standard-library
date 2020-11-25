/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2020-11-25
 *
 * */

#include <ls_std/serialization/logic/SerializableJSONStateConnection.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJSONStateConnection::SerializableJSONStateConnection(const std::shared_ptr<ls_std::StateConnection>& _value) :
Class("SerializableJSONStateConnection")
{
  this->_assignValue(_value);
}

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

void ls_std::SerializableJSONStateConnection::setValue(const std::shared_ptr<ls_std::StateConnection>& _value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls_std::SerializableJSONStateConnection::_assignValue(const std::shared_ptr<ls_std::StateConnection> &_value)
{
  if(_value == nullptr) {
    throw ls_std::IllegalArgumentException {};
  }

  this->value = _value;
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
