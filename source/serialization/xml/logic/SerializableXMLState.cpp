/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * */

#include "SerializableXMLState.hpp"
#include "../../../boxing/String.hpp"
#include "SerializableXMLStateConnection.hpp"

ls_std::SerializableXMLState::SerializableXMLState(std::shared_ptr<ls_std::State> _value) :
Class("SerializableXMLState"),
value(std::move(_value))
{}

ls_std::byte_field ls_std::SerializableXMLState::marshal()
{
  this->_update();
  tinyxml2::XMLPrinter printer {};
  this->document.Print(&printer);

  return printer.CStr();
}

void ls_std::SerializableXMLState::unmarshal(const ls_std::byte_field &_data)
{
  ls_std::String data {_data};
  this->document.Parse(data.getByteData().data());
  tinyxml2::XMLElement* root = this->document.RootElement();

  if(root != nullptr ) {
    this->_unmarshalConnections(root);
    this->_unmarshalId(root);
  }
}

std::shared_ptr<ls_std::State> ls_std::SerializableXMLState::getValue()
{
  return this->value;
}

void ls_std::SerializableXMLState::setValue(std::shared_ptr<ls_std::State> _value)
{
  this->value = std::move(_value);
  this->_clear();
}

void ls_std::SerializableXMLState::_clear()
{
  this->document.Clear();
}

void ls_std::SerializableXMLState::_unmarshalConnections(tinyxml2::XMLElement *_root)
{
  tinyxml2::XMLNode* connections = _root->FirstChildElement("connections");

  if(connections != nullptr) {
    tinyxml2::XMLNode* connection = connections->FirstChildElement("connection");
    tinyxml2::XMLPrinter printer{};
    this->value->clearConnections();

    do {
     if (connection != nullptr) {
       connection->Accept(&printer);
       ls_std::SerializableXMLStateConnection serializable{std::make_shared<ls_std::StateConnection>("", "")};
       serializable.unmarshal(printer.CStr());
       this->value->addStateConnection(serializable.getValue());
       connection = connection->NextSibling();
       printer.ClearBuffer();
     }
    }
    while(connection != nullptr);
  }
}

void ls_std::SerializableXMLState::_unmarshalId(tinyxml2::XMLElement* _root)
{
  const tinyxml2::XMLAttribute *attribute = _root->FindAttribute("id");

  if(attribute != nullptr) {
    this->value->setId(attribute->Value());
  }
}

void ls_std::SerializableXMLState::_update()
{
  this->_clear();
  tinyxml2::XMLNode* root = this->document.NewElement("state");
  this->document.InsertFirstChild(root);
  root->ToElement()->SetAttribute("id", this->value->getId().c_str());
  this->_updateStates();
}

void ls_std::SerializableXMLState::_updateStates()
{
  tinyxml2::XMLNode* connectionsNode = this->document.NewElement("connections");
  tinyxml2::XMLElement* stateNode = this->document.FirstChildElement("state");

  for(const auto& connection : this->value->getConnectedStates()) {
    ls_std::byte_field data = ls_std::SerializableXMLStateConnection {connection.second}.marshal();
    tinyxml2::XMLDocument connectionNodeDocument {};
    connectionNodeDocument.Parse(data.c_str());
    tinyxml2::XMLNode* connectionNode = connectionNodeDocument.RootElement();
    connectionsNode->InsertFirstChild(connectionNode);
  }

  stateNode->InsertEndChild(connectionsNode);
}
