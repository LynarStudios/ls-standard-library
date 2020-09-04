/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-09-04
 *
 * */

#include "SerializableJSONFloat.hpp"

ls_std::SerializableJSONFloat::SerializableJSONFloat(std::shared_ptr<ls_std::Float> _value) :
Class("SerializableJSONFloat"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONFloat::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONFloat::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->value = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONFloat::_update()
{
  this->jsonObject = {
      {"value", this->value->getValue()}
  };
}
