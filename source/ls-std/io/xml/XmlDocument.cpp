/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-30
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlDocument.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::io::XmlDeclaration;
using ls::std::io::XmlDocument;
using ls::std::io::XmlNode;
using std::shared_ptr;
using std::string;

XmlDocument::XmlDocument() : Class("XmlDocument")
{}

XmlDocument::~XmlDocument() noexcept = default;

shared_ptr<XmlDeclaration> XmlDocument::getDeclaration()
{
  return this->declaration;
}

shared_ptr<XmlNode> XmlDocument::getRootElement()
{
  return this->rootElement;
}

void XmlDocument::setDeclaration(const shared_ptr<XmlDeclaration> &_declaration)
{
  this->_assignDeclaration(_declaration);
}

void XmlDocument::setRootElement(const shared_ptr<XmlNode> &_rootElement)
{
  this->_assignRootElement(_rootElement);
}

string XmlDocument::toXml()
{
  string xmlString{};

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

void XmlDocument::_assignDeclaration(const shared_ptr<XmlDeclaration> &_declaration)
{
  NullPointerArgumentEvaluator{_declaration, "xml declaration reference is null!"}.evaluate();
  this->declaration = _declaration;
}

void XmlDocument::_assignRootElement(const shared_ptr<XmlNode> &_rootElement)
{
  NullPointerArgumentEvaluator{_rootElement, "xml root node reference is null!"}.evaluate();
  this->rootElement = _rootElement;
}
