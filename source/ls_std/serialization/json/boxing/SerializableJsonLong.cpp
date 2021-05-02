/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJsonLong.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonLong::SerializableJsonLong(const std::shared_ptr<ls_std::Long> &_value) : ls_std::Class("SerializableJsonLong")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonLong::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonLong::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if (this->jsonObject.contains("value"))
  {
    *this->value = this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Long> ls_std::SerializableJsonLong::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonLong::setValue(const std::shared_ptr<ls_std::Long> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonLong::_assignValue(const std::shared_ptr<ls_std::Long> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonLong::_update()
{
  this->jsonObject = {{"value", (ls_std::long_type) this->value->getValue()}};
}
