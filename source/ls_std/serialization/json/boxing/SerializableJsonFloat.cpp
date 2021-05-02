/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJsonFloat.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonFloat::SerializableJsonFloat(const std::shared_ptr<ls_std::Float> &_value) : ls_std::Class("SerializableJsonFloat")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonFloat::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonFloat::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if (this->jsonObject.contains("value"))
  {
    *this->value = this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Float> ls_std::SerializableJsonFloat::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonFloat::setValue(const std::shared_ptr<ls_std::Float> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonFloat::_assignValue(const std::shared_ptr<ls_std::Float> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonFloat::_update()
{
  this->jsonObject = {{"value", this->value->getValue()}};
}
