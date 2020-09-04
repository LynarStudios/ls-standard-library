/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-25
 * Changed:         2020-09-04
 *
 * */

#include "SerializableJSONLong.hpp"

ls_std::SerializableJSONLong::SerializableJSONLong(std::shared_ptr<ls_std::Long> _value) :
Class("SerializableJSONLong"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONLong::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONLong::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->value = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONLong::_update()
{
  this->jsonObject = {
      {"class", this->value->getClassName()},
      {"value", (ls_std::long_type) this->value->getValue()}
  };
}
