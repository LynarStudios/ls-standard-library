/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/xml/XmlDocument.hpp>

ls_std::XmlDocument::XmlDocument() : ls_std::Class("XmlDocument")
{}

std::shared_ptr<ls_std::XmlDeclaration> ls_std::XmlDocument::getDeclaration()
{
  return this->declaration;
}

std::shared_ptr<ls_std::XmlNode> ls_std::XmlDocument::getRootElement()
{
  return this->rootElement;
}

void ls_std::XmlDocument::setDeclaration(const std::shared_ptr<ls_std::XmlDeclaration> &_declaration)
{
  this->declaration = _declaration;
}

void ls_std::XmlDocument::setRootElement(const std::shared_ptr<ls_std::XmlNode> &_root)
{
  this->rootElement = _root;
}

std::string ls_std::XmlDocument::toXml()
{
  std::string xmlString{};

  if (this->declaration != nullptr)
  {
    xmlString = this->declaration->toXml();

    if (!xmlString.empty())
    {
      xmlString += "\n";
    }
  }

  return xmlString + this->rootElement->toXml();
}
