/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-10-29
 *
 * */

#include "SerializableJSONDouble.hpp"

ls_std::SerializableJSONDouble::SerializableJSONDouble(std::shared_ptr<ls_std::Double> _value) :
Class("SerializableJSONDouble"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableJSONDouble::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONDouble::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->value = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONDouble::_update()
{
  this->jsonObject = {
      {"value", this->value->getValue()}
  };
}
