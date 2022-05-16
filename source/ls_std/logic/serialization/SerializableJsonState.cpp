/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/logic/serialization/SerializableJsonState.hpp>
#include <ls_std/logic/serialization/SerializableJsonStateConnection.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::SerializableJsonState::SerializableJsonState(const ::std::shared_ptr<ls::std::logic::State> &_value) : ls::std::core::Class("SerializableJsonState")
{
  this->_assignValue(_value);
}

ls::std::core::type::byte_field ls::std::logic::SerializableJsonState::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::std::logic::SerializableJsonState::unmarshal(const ls::std::core::type::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStateConnections();
  this->value->setId(this->jsonObject["id"]);
}

std::shared_ptr<ls::std::logic::State> ls::std::logic::SerializableJsonState::getValue()
{
  return this->value;
}

void ls::std::logic::SerializableJsonState::setValue(const ::std::shared_ptr<ls::std::logic::State> &_value)
{
  this->_assignValue(_value);
  this->_clear();
}

void ls::std::logic::SerializableJsonState::_assignValue(const ::std::shared_ptr<ls::std::logic::State> &_value)
{
  if (_value == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::std::logic::SerializableJsonState::_clear()
{
  this->jsonObject.clear();
}

void ls::std::logic::SerializableJsonState::_unmarshalStateConnections()
{
  if (!this->jsonObject["connectedStates"].empty())
  {
    this->value->clearConnections();

    for (const auto &connectionJson : this->jsonObject["connectedStates"])
    {
      ::std::shared_ptr<ls::std::logic::StateConnection> connection = ::std::make_shared<ls::std::logic::StateConnection>("TMP_ID", "TMP_ID");
      ls::std::logic::SerializableJsonStateConnection{connection}.unmarshal(connectionJson.dump());
      this->value->addStateConnection(connection);
    }
  }
}

void ls::std::logic::SerializableJsonState::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateStateConnections();
}

void ls::std::logic::SerializableJsonState::_updateStateConnections()
{
  ::std::string jsonString{};

  for (const auto &connection : this->value->getConnectedStates())
  {
    jsonString = ls::std::logic::SerializableJsonStateConnection{connection.second}.marshal();
    this->jsonObject["connectedStates"][connection.first] = nlohmann::json::parse(jsonString);
  }
}
