/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2021-09-19
 *
 * */

#include <ls_std/serialization/json/event/SerializableJsonEvent.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonEvent::SerializableJsonEvent(const std::shared_ptr<ls_std::Event> &_value) : ls_std::Class("SerializableJsonEvent")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonEvent::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

std::shared_ptr<ls_std::Event> ls_std::SerializableJsonEvent::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonEvent::setValue(const std::shared_ptr<ls_std::Event> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonEvent::_assignValue(const std::shared_ptr<ls_std::Event> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJson : this->jsonObject["parameterList"])
  {
    ls_std::event_parameter parameter = {parameterJson.at(0), parameterJson.at(1)};
    this->value->addParameter(parameter);
  }
}

void ls_std::SerializableJsonEvent::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateEventParameterList();
}

void ls_std::SerializableJsonEvent::_updateEventParameterList()
{
  std::string jsonString{};

  for (const auto &eventParameter : this->value->getParameterList())
  {
    nlohmann::json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
