/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2021-07-16
 *
 * */

#include <ls_std/io/xml/XmlDeclaration.hpp>

ls_std::XmlDeclaration::XmlDeclaration(const std::string& _version) : ls_std::Class("XmlDeclaration")
{
  this->version.setValue(_version);
}

std::string ls_std::XmlDeclaration::getEncoding()
{
  return this->encoding.getValue();
}

std::string ls_std::XmlDeclaration::getStandalone()
{
  return this->standalone.getValue();
}

std::string ls_std::XmlDeclaration::getVersion()
{
  return this->version.getValue();
}

void ls_std::XmlDeclaration::setEncoding(const std::string& _encoding)
{
  this->encoding.setValue(_encoding);
}

void ls_std::XmlDeclaration::setStandalone(const std::string& _standalone)
{
  this->standalone.setValue(_standalone);
}

void ls_std::XmlDeclaration::setVersion(const std::string& _version)
{
  this->version.setValue(_version);
}

std::string ls_std::XmlDeclaration::toXml()
{
  std::string declaration = "<?xml";

  declaration += ls_std::XmlDeclaration::_toXmlAttribute(this->version);
  declaration += ls_std::XmlDeclaration::_toXmlAttribute(this->encoding);
  declaration += ls_std::XmlDeclaration::_toXmlAttribute(this->standalone);

  return declaration + " ?>";
}

std::string ls_std::XmlDeclaration::_toXmlAttribute(ls_std::XmlAttribute _attribute)
{
  std::string xmlString{};

  if (!_attribute.getValue().empty())
  {
    xmlString = " " + _attribute.toXml();
  }

  return xmlString;
}
