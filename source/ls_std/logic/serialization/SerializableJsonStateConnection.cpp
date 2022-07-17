/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-07-14
 *
 * */

#include <ls_std/logic/serialization/SerializableJsonStateConnection.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::SerializableJsonStateConnection::SerializableJsonStateConnection(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value) : ls::std::core::Class("SerializableJsonStateConnection")
{
  this->_assignValue(_value);
}

ls::std::core::type::byte_field ls::std::logic::SerializableJsonStateConnection::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::std::logic::SerializableJsonStateConnection::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ::std::string jsonString = ::std::string(_data);
  this->jsonObject = ls::std::core::type::json::parse(jsonString);

  this->value->setConnectionId(this->jsonObject["connectionId"]);
  this->value->setStateId(this->jsonObject["stateId"]);
  this->value->updatePassCondition(this->jsonObject["condition"]);
}

::std::shared_ptr<ls::std::logic::StateConnection> ls::std::logic::SerializableJsonStateConnection::getValue()
{
  return this->value;
}

void ls::std::logic::SerializableJsonStateConnection::setValue(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls::std::logic::SerializableJsonStateConnection::_assignValue(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value)
{
  if (_value == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::std::logic::SerializableJsonStateConnection::_clear()
{
  this->jsonObject.clear();
}

void ls::std::logic::SerializableJsonStateConnection::_update()
{
  this->jsonObject = {{"condition",    this->value->isPassable()},
                      {"connectionId", this->value->getConnectionId()},
                      {"stateId",      this->value->getStateId()}};
}
