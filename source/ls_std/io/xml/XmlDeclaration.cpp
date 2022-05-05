/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/xml/XmlDeclaration.hpp>

ls::XmlDeclaration::XmlDeclaration(const std::string& _version) : ls::Class("XmlDeclaration")
{
  this->version.setValue(_version);
}

std::string ls::XmlDeclaration::getEncoding()
{
  return this->encoding.getValue();
}

std::string ls::XmlDeclaration::getStandalone()
{
  return this->standalone.getValue();
}

std::string ls::XmlDeclaration::getVersion()
{
  return this->version.getValue();
}

void ls::XmlDeclaration::setEncoding(const std::string& _encoding)
{
  this->encoding.setValue(_encoding);
}

void ls::XmlDeclaration::setStandalone(const std::string& _standalone)
{
  this->standalone.setValue(_standalone);
}

void ls::XmlDeclaration::setVersion(const std::string& _version)
{
  this->version.setValue(_version);
}

std::string ls::XmlDeclaration::toXml()
{
  std::string declaration = "<?xml";

  declaration += ls::XmlDeclaration::_toXmlAttribute(this->version);
  declaration += ls::XmlDeclaration::_toXmlAttribute(this->encoding);
  declaration += ls::XmlDeclaration::_toXmlAttribute(this->standalone);

  return declaration + " ?>";
}

std::string ls::XmlDeclaration::_toXmlAttribute(ls::XmlAttribute _attribute)
{
  std::string xmlString{};

  if (!_attribute.getValue().empty())
  {
    xmlString = " " + _attribute.toXml();
  }

  return xmlString;
}
