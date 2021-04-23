/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/serialization/event/SerializableJSONEvent.hpp>
#include <ls_std/exception/NullPointerException.hpp>

ls_std::SerializableJSONEvent::SerializableJSONEvent(const std::shared_ptr<ls_std::Event> &_value) : ls_std::Class("SerializableJSONEvent")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJSONEvent::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONEvent::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->value->setId(this->jsonObject["id"]);
  this->_unmarshalParameterList();
}

std::shared_ptr<ls_std::Event> ls_std::SerializableJSONEvent::getValue()
{
  return this->value;
}

void ls_std::SerializableJSONEvent::setValue(const std::shared_ptr<ls_std::Event> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJSONEvent::_assignValue(const std::shared_ptr<ls_std::Event> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::NullPointerException{};
  }

  this->value = _value;
}

void ls_std::SerializableJSONEvent::_unmarshalParameterList()
{
  this->value->clearParameterList();

  for (const auto &parameterJSON : this->jsonObject["parameterList"])
  {
    ls_std::event_parameter parameter = {parameterJSON.at(0), parameterJSON.at(1)};
    this->value->addParameter(parameter);
  }
}

void ls_std::SerializableJSONEvent::_update()
{
  this->jsonObject = {{"id", this->value->getId()}};

  this->_updateEventParameterList();
}

void ls_std::SerializableJSONEvent::_updateEventParameterList()
{
  std::string jsonString{};

  for (const auto &eventParameter : this->value->getParameterList())
  {
    nlohmann::json parameterJson = {eventParameter.first, eventParameter.second};
    this->jsonObject["parameterList"][eventParameter.first] = parameterJson;
  }
}
