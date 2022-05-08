/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2022-05-08
 *
 * */

#include "ls_std/event/serialization/SerializableJsonEvent.hpp"
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::event::SerializableJsonEvent::SerializableJsonEvent(const ::std::shared_ptr<ls::std::event::Event> &_value) : ls::Class("SerializableJsonEvent")
{
  this->_assignValue(_value);
}

ls::byte_field ls::std::event::SerializableJsonEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::std::event::SerializableJsonEvent::unmarshal(const ls::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

std::shared_ptr<ls::std::event::Event> ls::std::event::SerializableJsonEvent::getValue()
{
  return this->value;
}

void ls::std::event::SerializableJsonEvent::setValue(const ::std::shared_ptr<ls::std::event::Event> &_value)
{
  this->_assignValue(_value);
}

void ls::std::event::SerializableJsonEvent::_assignValue(const ::std::shared_ptr<ls::std::event::Event> &_value)
{
  if (_value == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::std::event::SerializableJsonEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJson : this->jsonObject["parameterList"])
  {
    ls::std::event::event_parameter parameter = {parameterJson.at(0), parameterJson.at(1)};
    this->value->addParameter(parameter);
  }
}

void ls::std::event::SerializableJsonEvent::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateEventParameterList();
}

void ls::std::event::SerializableJsonEvent::_updateEventParameterList()
{
  ::std::string jsonString{};

  for (const auto &eventParameter : this->value->getParameterList())
  {
    nlohmann::json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
