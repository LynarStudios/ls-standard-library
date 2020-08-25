/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-08-23
 *
 * */

#include "SerializableJSONInteger.hpp"

ls_std::SerializableJSONInteger::SerializableJSONInteger(std::shared_ptr<ls_std::Integer> _integer) : Class("SerializableJSONInteger"),
integer(std::move(_integer))
{}

ls_std::byte_field ls_std::SerializableJSONInteger::marshal()
{
  this->_update();
  auto* data = new char[this->jsonObject.dump().size() + 1];
  strcpy(data, this->jsonObject.dump().c_str());

  return data;
}

void ls_std::SerializableJSONInteger::unmarshal(const ls_std::byte_field& _data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if(this->jsonObject.contains("value")) {
    *this->integer = this->jsonObject["value"];
  }
}

void ls_std::SerializableJSONInteger::_update()
{
  this->jsonObject = {
      {"class", this->integer->getClassName()},
      {"value", this->integer->getValue()}
  };
}
