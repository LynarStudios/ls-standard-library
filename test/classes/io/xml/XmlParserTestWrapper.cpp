/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2023-02-23
 *
 * */

#include "XmlParserTestWrapper.hpp"

using ls::std::core::type::byte_field;
using ls::std::io::XmlParser;
using std::list;
using std::move;
using std::pair;
using std::string;
using test::io::XmlParserTestWrapper;

XmlParserTestWrapper::XmlParserTestWrapper() : XmlParser(nullptr)
{}

XmlParserTestWrapper::~XmlParserTestWrapper() = default;

pair<string, string> XmlParserTestWrapper::readAttribute(const byte_field &_data)
{
  return XmlParser::_readAttribute_(_data);
}

list<pair<string, string>> XmlParserTestWrapper::readAttributes(byte_field _data)
{
  return XmlParser::_readAttributes_(::move(_data));
}
