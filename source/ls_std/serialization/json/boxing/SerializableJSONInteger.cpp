/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-10-29
 *
 * */

#include "SerializableJSONInteger.hpp"

ls_std::SerializableJSONInteger::SerializableJSONInteger(std::shared_ptr<ls_std::Integer> _value) :
Class("SerializableJSONInteger"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONInteger::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONInteger::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->value = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONInteger::_update()
{
  this->jsonObject = {
      {"value", this->value->getValue()}
  };
}
