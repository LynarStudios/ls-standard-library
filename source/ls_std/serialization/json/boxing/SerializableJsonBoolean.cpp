/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJsonBoolean.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonBoolean::SerializableJsonBoolean(const std::shared_ptr<ls_std::Boolean> &_value) : ls_std::Class("SerializableJsonBoolean")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonBoolean::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonBoolean::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  if (this->jsonObject.contains("value"))
  {
    *this->value = (bool) this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Boolean> ls_std::SerializableJsonBoolean::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonBoolean::setValue(const std::shared_ptr<ls_std::Boolean> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonBoolean::_assignValue(const std::shared_ptr<ls_std::Boolean> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonBoolean::_update()
{
  this->jsonObject = {{"value", this->value->getValue()}};
}
