/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/event/serialization/SerializableJsonEvent.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::core::type::event_parameter;
using ls::std::core::type::json;
using ls::std::event::Event;
using ls::std::event::SerializableJsonEvent;
using std::shared_ptr;
using std::string;

SerializableJsonEvent::SerializableJsonEvent(const shared_ptr<Event> &_value) : Class("SerializableJsonEvent")
{
  this->_assignValue(_value);
}

SerializableJsonEvent::~SerializableJsonEvent() noexcept = default;

byte_field SerializableJsonEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void SerializableJsonEvent::unmarshal(const byte_field &_data)
{
  this->jsonObject = json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

shared_ptr<Event> SerializableJsonEvent::getValue()
{
  return this->value;
}

void SerializableJsonEvent::setValue(const shared_ptr<Event> &_value)
{
  this->_assignValue(_value);
}

void SerializableJsonEvent::_assignValue(const shared_ptr<Event> &_value)
{
  NullPointerArgumentEvaluator{_value, "event reference for serialization attempt is null!"}.evaluate();
  this->value = _value;
}

void SerializableJsonEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJson : this->jsonObject["parameterList"])
  {
    event_parameter parameter = {parameterJson.at(0), parameterJson.at(1)};
    this->value->addParameter(parameter);
  }
}

void SerializableJsonEvent::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateEventParameterList();
}

void SerializableJsonEvent::_updateEventParameterList()
{
  string jsonString{};

  for (const auto &eventParameter : this->value->getParameterList())
  {
    json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
