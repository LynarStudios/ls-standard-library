/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlDocument.hpp>

ls::std::io::XmlDocument::XmlDocument() : ls::std::core::Class("XmlDocument")
{}

ls::std::io::XmlDocument::~XmlDocument() = default;

::std::shared_ptr<ls::std::io::XmlDeclaration> ls::std::io::XmlDocument::getDeclaration()
{
  return this->declaration;
}

::std::shared_ptr<ls::std::io::XmlNode> ls::std::io::XmlDocument::getRootElement()
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

::std::string ls::std::io::XmlDocument::toXml()
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
  ls::std::core::NullPointerArgumentEvaluator{_declaration, "xml declaration reference is null!"}.evaluate();
  this->declaration = _declaration;
}

void ls::std::io::XmlDocument::_assignRootElement(const ::std::shared_ptr<ls::std::io::XmlNode> &_rootElement)
{
  ls::std::core::NullPointerArgumentEvaluator{_rootElement, "xml root node reference is null!"}.evaluate();
  this->rootElement = _rootElement;
}
