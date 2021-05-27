/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/serialization/json/boxing/SerializableJsonDouble.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonDouble::SerializableJsonDouble(const std::shared_ptr<ls_std::Double> &_value) : ls_std::Class("SerializableJsonDouble")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonDouble::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonDouble::unmarshal(const ls_std::byte_field &_data)
{
  std::string jsonString = std::string(_data);
  this->jsonObject = nlohmann::json::parse(jsonString);

  if (this->jsonObject.contains("value"))
  {
    *this->value = this->jsonObject["value"];
  }
}

std::shared_ptr<ls_std::Double> ls_std::SerializableJsonDouble::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonDouble::setValue(const std::shared_ptr<ls_std::Double> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonDouble::_assignValue(const std::shared_ptr<ls_std::Double> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonDouble::_update()
{
  this->jsonObject = {{"value", this->value->getValue()}};
}
