/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-29
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/xml/XMLDeclaration.hpp>

ls_std::XMLDeclaration::XMLDeclaration(std::string _version) : ls_std::Class("XMLDeclaration")
{
  this->version.setValue(std::move(_version));
}

std::string ls_std::XMLDeclaration::getEncoding()
{
  return this->encoding.getValue();
}

std::string ls_std::XMLDeclaration::getStandalone()
{
  return this->standalone.getValue();
}

std::string ls_std::XMLDeclaration::getVersion()
{
  return this->version.getValue();
}

void ls_std::XMLDeclaration::setEncoding(std::string _encoding)
{
  this->encoding.setValue(std::move(_encoding));
}

void ls_std::XMLDeclaration::setStandalone(std::string _standalone)
{
  this->standalone.setValue(std::move(_standalone));
}

void ls_std::XMLDeclaration::setVersion(std::string _version)
{
  this->version.setValue(std::move(_version));
}

std::string ls_std::XMLDeclaration::toXML()
{
  std::string declaration = "<?xml";

  declaration += ls_std::XMLDeclaration::_toXMLAttribute(this->version);
  declaration += ls_std::XMLDeclaration::_toXMLAttribute(this->encoding);
  declaration += ls_std::XMLDeclaration::_toXMLAttribute(this->standalone);

  return declaration + " ?>";
}

std::string ls_std::XMLDeclaration::_toXMLAttribute(ls_std::XMLAttribute _attribute)
{
  std::string xmlString{};

  if (!_attribute.getValue().empty())
  {
    xmlString = " " + _attribute.toXML();
  }

  return xmlString;
}
