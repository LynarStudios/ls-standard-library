/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/io/xml/XMLParserMock.hpp>

ls_std::XMLParserMock::XMLParserMock() : ls_std::XMLParser(nullptr)
{}

std::pair<std::string, std::string> ls_std::XMLParserMock::readAttribute(const ls_std::byte_field &_data)
{
  return ls_std::XMLParser::_readAttribute_(_data);
}

std::list<std::pair<std::string, std::string>> ls_std::XMLParserMock::readAttributes(ls_std::byte_field _data)
{
  return ls_std::XMLParser::_readAttributes_(std::move(_data));
}
