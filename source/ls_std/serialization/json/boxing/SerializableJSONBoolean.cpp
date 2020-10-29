/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-10-29
 *
 * */

#include "SerializableJSONBoolean.hpp"

ls_std::SerializableJSONBoolean::SerializableJSONBoolean(std::shared_ptr<ls_std::Boolean> _value) :
Class("SerializableJSONBoolean"),
value(std::move(_value))
{}

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

void ls_std::SerializableJSONBoolean::_update()
{
  this->jsonObject = {
      {"value", this->value->getValue()}
  };
}
