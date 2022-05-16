/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/xml/XmlDocument.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::io::XmlDocument::XmlDocument() : ls::std::core::Class("XmlDocument")
{}

std::shared_ptr<ls::std::io::XmlDeclaration> ls::std::io::XmlDocument::getDeclaration()
{
  return this->declaration;
}

std::shared_ptr<ls::std::io::XmlNode> ls::std::io::XmlDocument::getRootElement()
{
  return this->rootElement;
}

void ls::std::io::XmlDocument::setDeclaration(const ::std::shared_ptr<ls::std::io::XmlDeclaration> &_declaration)
{
  this->_assignDeclaration(_declaration);
}

void ls::std::io::XmlDocument::setRootElement(const ::std::shared_ptr<ls::std::io::XmlNode> &_rootElement)
{
  this->_assignRootElement(_rootElement);
}

std::string ls::std::io::XmlDocument::toXml()
{
  ::std::string xmlString{};

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

void ls::std::io::XmlDocument::_assignDeclaration(const ::std::shared_ptr<ls::std::io::XmlDeclaration> &_declaration)
{
  if (_declaration == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->declaration = _declaration;
}

void ls::std::io::XmlDocument::_assignRootElement(const ::std::shared_ptr<ls::std::io::XmlNode> &_rootElement)
{
  if (_rootElement == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->rootElement = _rootElement;
}
