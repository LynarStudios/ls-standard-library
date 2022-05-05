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
  this->_assignDeclaration(_declaration);
}

void ls_std::XmlDocument::setRootElement(const std::shared_ptr<ls_std::XmlNode> &_rootElement)
{
  this->_assignRootElement(_rootElement);
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

void ls_std::XmlDocument::_assignDeclaration(const std::shared_ptr<ls_std::XmlDeclaration> &_declaration)
{
  if (_declaration == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->declaration = _declaration;
}

void ls_std::XmlDocument::_assignRootElement(const std::shared_ptr<ls_std::XmlNode> &_rootElement)
{
  if (_rootElement == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->rootElement = _rootElement;
}
