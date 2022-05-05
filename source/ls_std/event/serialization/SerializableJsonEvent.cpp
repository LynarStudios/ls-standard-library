/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2022-05-05
 *
 * */

#include "ls_std/event/serialization/SerializableJsonEvent.hpp"
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::SerializableJsonEvent::SerializableJsonEvent(const std::shared_ptr<ls::Event> &_value) : ls::Class("SerializableJsonEvent")
{
  this->_assignValue(_value);
}

ls::byte_field ls::SerializableJsonEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::SerializableJsonEvent::unmarshal(const ls::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

std::shared_ptr<ls::Event> ls::SerializableJsonEvent::getValue()
{
  return this->value;
}

void ls::SerializableJsonEvent::setValue(const std::shared_ptr<ls::Event> &_value)
{
  this->_assignValue(_value);
}

void ls::SerializableJsonEvent::_assignValue(const std::shared_ptr<ls::Event> &_value)
{
  if (_value == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::SerializableJsonEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJson : this->jsonObject["parameterList"])
  {
    ls::event_parameter parameter = {parameterJson.at(0), parameterJson.at(1)};
    this->value->addParameter(parameter);
  }
}

void ls::SerializableJsonEvent::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateEventParameterList();
}

void ls::SerializableJsonEvent::_updateEventParameterList()
{
  std::string jsonString{};

  for (const auto &eventParameter : this->value->getParameterList())
  {
    nlohmann::json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
