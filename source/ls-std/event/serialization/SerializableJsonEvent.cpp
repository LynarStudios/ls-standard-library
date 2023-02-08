/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/event/serialization/SerializableJsonEvent.hpp>

ls::std::event::SerializableJsonEvent::SerializableJsonEvent(const ::std::shared_ptr<ls::std::event::Event> &_value) : ls::std::core::Class("SerializableJsonEvent")
{
  this->_assignValue(_value);
}

ls::std::event::SerializableJsonEvent::~SerializableJsonEvent() = default;

ls::std::core::type::byte_field ls::std::event::SerializableJsonEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::std::event::SerializableJsonEvent::unmarshal(const ls::std::core::type::byte_field &_data)
{
  this->jsonObject = ls::std::core::type::json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

::std::shared_ptr<ls::std::event::Event> ls::std::event::SerializableJsonEvent::getValue()
{
  return this->value;
}

void ls::std::event::SerializableJsonEvent::setValue(const ::std::shared_ptr<ls::std::event::Event> &_value)
{
  this->_assignValue(_value);
}

void ls::std::event::SerializableJsonEvent::_assignValue(const ::std::shared_ptr<ls::std::event::Event> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value, "event reference for serialization attempt is null!"}.evaluate();
  this->value = _value;
}

void ls::std::event::SerializableJsonEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJson : this->jsonObject["parameterList"])
  {
    ls::std::core::type::event_parameter parameter = {parameterJson.at(0), parameterJson.at(1)};
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
    ls::std::core::type::json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
