/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/xml/XmlDocument.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::XmlDocument::XmlDocument() : ls::Class("XmlDocument")
{}

std::shared_ptr<ls::XmlDeclaration> ls::XmlDocument::getDeclaration()
{
  return this->declaration;
}

std::shared_ptr<ls::XmlNode> ls::XmlDocument::getRootElement()
{
  return this->rootElement;
}

void ls::XmlDocument::setDeclaration(const std::shared_ptr<ls::XmlDeclaration> &_declaration)
{
  this->_assignDeclaration(_declaration);
}

void ls::XmlDocument::setRootElement(const std::shared_ptr<ls::XmlNode> &_rootElement)
{
  this->_assignRootElement(_rootElement);
}

std::string ls::XmlDocument::toXml()
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

void ls::XmlDocument::_assignDeclaration(const std::shared_ptr<ls::XmlDeclaration> &_declaration)
{
  if (_declaration == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->declaration = _declaration;
}

void ls::XmlDocument::_assignRootElement(const std::shared_ptr<ls::XmlNode> &_rootElement)
{
  if (_rootElement == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->rootElement = _rootElement;
}
