/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2023-02-04
 *
 * */

#include <ls-std/io/xml/XmlDeclaration.hpp>

ls::std::io::XmlDeclaration::XmlDeclaration(const ::std::string &_version) : ls::std::core::Class("XmlDeclaration")
{
  this->version.setValue(_version);
}

ls::std::io::XmlDeclaration::~XmlDeclaration() = default;

::std::string ls::std::io::XmlDeclaration::getEncoding()
{
  return this->encoding.getValue();
}

::std::string ls::std::io::XmlDeclaration::getStandalone()
{
  return this->standalone.getValue();
}

::std::string ls::std::io::XmlDeclaration::getVersion()
{
  return this->version.getValue();
}

void ls::std::io::XmlDeclaration::setEncoding(const ::std::string &_encoding)
{
  this->encoding.setValue(_encoding);
}

void ls::std::io::XmlDeclaration::setStandalone(const ::std::string &_standalone)
{
  this->standalone.setValue(_standalone);
}

void ls::std::io::XmlDeclaration::setVersion(const ::std::string &_version)
{
  this->version.setValue(_version);
}

::std::string ls::std::io::XmlDeclaration::toXml()
{
  ::std::string declaration = "<?xml";

  declaration += ls::std::io::XmlDeclaration::_toXmlAttribute(this->version);
  declaration += ls::std::io::XmlDeclaration::_toXmlAttribute(this->encoding);
  declaration += ls::std::io::XmlDeclaration::_toXmlAttribute(this->standalone);

  return declaration + " ?>";
}

::std::string ls::std::io::XmlDeclaration::_toXmlAttribute(ls::std::io::XmlAttribute _attribute)
{
  ::std::string xmlString{};

  if (!_attribute.getValue().empty())
  {
    xmlString = " " + _attribute.toXml();
  }

  return xmlString;
}
