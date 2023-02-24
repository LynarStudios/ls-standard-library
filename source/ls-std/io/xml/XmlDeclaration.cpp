/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/io/xml/XmlDeclaration.hpp>

using ls::std::io::XmlAttribute;
using ls::std::io::XmlDeclaration;
using std::string;

XmlDeclaration::XmlDeclaration(const string &_version) : ls::std::core::Class("XmlDeclaration")
{
  this->version.setValue(_version);
}

XmlDeclaration::~XmlDeclaration() noexcept = default;

string XmlDeclaration::getEncoding()
{
  return this->encoding.getValue();
}

string XmlDeclaration::getStandalone()
{
  return this->standalone.getValue();
}

string XmlDeclaration::getVersion()
{
  return this->version.getValue();
}

void XmlDeclaration::setEncoding(const string &_encoding)
{
  this->encoding.setValue(_encoding);
}

void XmlDeclaration::setStandalone(const string &_standalone)
{
  this->standalone.setValue(_standalone);
}

void XmlDeclaration::setVersion(const string &_version)
{
  this->version.setValue(_version);
}

string XmlDeclaration::toXml()
{
  string declaration = "<?xml";

  declaration += XmlDeclaration::_toXmlAttribute(this->version);
  declaration += XmlDeclaration::_toXmlAttribute(this->encoding);
  declaration += XmlDeclaration::_toXmlAttribute(this->standalone);

  return declaration + " ?>";
}

string XmlDeclaration::_toXmlAttribute(XmlAttribute _attribute)
{
  string xmlString{};

  if (!_attribute.getValue().empty())
  {
    xmlString = " " + _attribute.toXml();
  }

  return xmlString;
}
