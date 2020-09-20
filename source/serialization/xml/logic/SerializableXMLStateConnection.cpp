/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * */

#include "SerializableXMLStateConnection.hpp"
#include "../../../boxing/String.hpp"
#include "../../../boxing/Boolean.hpp"

ls_std::SerializableXMLStateConnection::SerializableXMLStateConnection(std::shared_ptr<StateConnection> _value) :
Class("SerializableXMLStateConnection"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableXMLStateConnection::marshal()
{
  this->_update();
  tinyxml2::XMLPrinter printer {};
  this->document.Print(&printer);
  return ls_std::byte_field(printer.CStr());
}

void ls_std::SerializableXMLStateConnection::unmarshal(const ls_std::byte_field &_data)
{
  ls_std::String data {_data};
  this->document.Parse(data.getByteData().data());
  this->_unmarshalConnectionId();
  this->_unmarshalCondition();
  this->_unmarshalId();
}

std::shared_ptr<ls_std::StateConnection> ls_std::SerializableXMLStateConnection::getValue()
{
  return this->value;
}

void ls_std::SerializableXMLStateConnection::setValue(std::shared_ptr<StateConnection> _value)
{
  this->value = std::move(_value);
  this->_clear();
}

void ls_std::SerializableXMLStateConnection::_clear()
{
  this->document.Clear();
}

void ls_std::SerializableXMLStateConnection::_unmarshalCondition()
{
  ls_std::Boolean condition {};
  const tinyxml2::XMLAttribute *attribute = this->document.RootElement()->FindAttribute("condition");

  if(attribute != nullptr) {
    condition.parse(attribute->Value());
    this->value->updatePassCondition(condition.getValue());
  }
}

void ls_std::SerializableXMLStateConnection::_unmarshalConnectionId()
{
  const tinyxml2::XMLAttribute *attribute = this->document.RootElement()->FindAttribute("connectionId");

  if(attribute != nullptr) {
    this->value->setConnectionId(attribute->Value());
  }
}

void ls_std::SerializableXMLStateConnection::_unmarshalId()
{
  const tinyxml2::XMLAttribute *attribute = this->document.RootElement()->FindAttribute("id");

  if(attribute != nullptr) {
    this->value->setStateId(attribute->Value());
  }
}

void ls_std::SerializableXMLStateConnection::_update()
{
  this->_clear();
  tinyxml2::XMLNode* root = this->document.NewElement("connection");
  this->document.InsertFirstChild(root);

  root->ToElement()->SetAttribute("connectionId", this->value->getConnectionId().c_str());
  root->ToElement()->SetAttribute("id", this->value->getStateId().c_str());
  root->ToElement()->SetAttribute("condition", this->value->isPassable());
}
