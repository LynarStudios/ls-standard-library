/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2020-09-04
 *
 * */

#include "SerializableJSONString.hpp"

ls_std::SerializableJSONString::SerializableJSONString(std::shared_ptr<ls_std::String> _value) :
Class("SerializableJSONString"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONString::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONString::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->value = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONString::_update()
{
  this->jsonObject = {
      {"value", this->value->toString()}
  };
}
