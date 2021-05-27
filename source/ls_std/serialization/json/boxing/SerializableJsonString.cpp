/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJsonString.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonString::SerializableJsonString(const std::shared_ptr<ls_std::String> &_value) : ls_std::Class("SerializableJsonString")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonString::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonString::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  if (this->jsonObject.contains("value"))
  {
    *this->value = this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::String> ls_std::SerializableJsonString::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonString::setValue(const std::shared_ptr<ls_std::String> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonString::_assignValue(const std::shared_ptr<ls_std::String> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonString::_update()
{
  this->jsonObject = {{"value", this->value->toString()}};
}
