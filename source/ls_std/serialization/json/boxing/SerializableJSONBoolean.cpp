/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/serialization/boxing/SerializableJSONBoolean.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJSONBoolean::SerializableJSONBoolean(const std::shared_ptr<ls_std::Boolean>& _value) :
Class("SerializableJSONBoolean")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJSONBoolean::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONBoolean::unmarshal(const ls_std::byte_field& _data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  if(this->jsonObject.contains("value")) {
    *this->value = (bool) this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Boolean> ls_std::SerializableJSONBoolean::getValue()
{
  return this->value;
}

void ls_std::SerializableJSONBoolean::setValue(const std::shared_ptr<ls_std::Boolean> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJSONBoolean::_assignValue(const std::shared_ptr<ls_std::Boolean> &_value)
{
  if(_value == nullptr) {
    throw ls_std::IllegalArgumentException {};
  }

  this->value = _value;
}

void ls_std::SerializableJSONBoolean::_update()
{
  this->jsonObject = {
      {"value", this->value->getValue()}
  };
}
