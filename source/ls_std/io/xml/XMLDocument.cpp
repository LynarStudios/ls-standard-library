/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/io/xml/XMLDocument.hpp>

ls_std::XMLDocument::XMLDocument() : ls_std::Class("XMLDocument")
{}

std::shared_ptr<ls_std::XMLDeclaration> ls_std::XMLDocument::getDeclaration()
{
  return this->declaration;
}

std::shared_ptr<ls_std::XMLNode> ls_std::XMLDocument::getRootElement()
{
  return this->rootElement;
}

void ls_std::XMLDocument::setDeclaration(const std::shared_ptr<ls_std::XMLDeclaration> &_declaration)
{
  this->declaration = _declaration;
}

void ls_std::XMLDocument::setRootElement(const std::shared_ptr<ls_std::XMLNode> &_root)
{
  this->rootElement = _root;
}

std::string ls_std::XMLDocument::toXML()
{
  std::string xmlString {};

  if(this->declaration != nullptr) {
    xmlString = this->declaration->toXML();

    if(!xmlString.empty()) {
      xmlString += "\n";
    }
  }

  return xmlString + this->rootElement->toXML();
}
