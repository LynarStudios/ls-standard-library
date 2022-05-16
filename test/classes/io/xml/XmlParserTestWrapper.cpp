/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2022-05-14
 *
 * */

#include "XmlParserTestWrapper.hpp"

ls_std_io_test::XmlParserTestWrapper::XmlParserTestWrapper() : ls::std::io::XmlParser(nullptr)
{}

std::pair<std::string, std::string> ls_std_io_test::XmlParserTestWrapper::readAttribute(const ls::std::core::type::byte_field &_data)
{
  return ls::std::io::XmlParser::_readAttribute_(_data);
}

std::list<std::pair<std::string, std::string>> ls_std_io_test::XmlParserTestWrapper::readAttributes(ls::std::core::type::byte_field _data)
{
  return ls::std::io::XmlParser::_readAttributes_(std::move(_data));
}
