/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2021-05-01
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJSONInteger.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJSONInteger::SerializableJSONInteger(const std::shared_ptr<ls_std::Integer> &_value) : ls_std::Class("SerializableJSONInteger")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJSONInteger::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONInteger::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if (this->jsonObject.contains("value"))
  {
    *this->value = this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Integer> ls_std::SerializableJSONInteger::getValue()
{
  return this->value;
}

void ls_std::SerializableJSONInteger::setValue(const std::shared_ptr<ls_std::Integer> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJSONInteger::_assignValue(const std::shared_ptr<ls_std::Integer> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJSONInteger::_update()
{
  this->jsonObject = {{"value", this->value->getValue()}};
}
