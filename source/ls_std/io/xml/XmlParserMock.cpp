/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/xml/XmlParserMock.hpp>

ls_std::XmlParserMock::XmlParserMock() : ls_std::XmlParser(nullptr)
{}

std::pair<std::string, std::string> ls_std::XmlParserMock::readAttribute(const ls_std::byte_field &_data)
{
  return ls_std::XmlParser::_readAttribute_(_data);
}

std::list<std::pair<std::string, std::string>> ls_std::XmlParserMock::readAttributes(ls_std::byte_field _data)
{
  return ls_std::XmlParser::_readAttributes_(std::move(_data));
}
