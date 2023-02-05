/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2023-02-05
 *
 * */

#include "XmlParserTestWrapper.hpp"

test::io::XmlParserTestWrapper::XmlParserTestWrapper() : ls::std::io::XmlParser(nullptr)
{}

test::io::XmlParserTestWrapper::~XmlParserTestWrapper() = default;

::std::pair<::std::string, ::std::string> test::io::XmlParserTestWrapper::readAttribute(const ls::std::core::type::byte_field &_data)
{
  return ls::std::io::XmlParser::_readAttribute_(_data);
}

::std::list<::std::pair<::std::string, ::std::string>> test::io::XmlParserTestWrapper::readAttributes(ls::std::core::type::byte_field _data)
{
  return ls::std::io::XmlParser::_readAttributes_(::std::move(_data));
}
