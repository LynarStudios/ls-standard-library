/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2020-10-29
 *
 * */

#include "XMLReaderMock.hpp"

ls_std::XMLReaderMock::XMLReaderMock() : XMLReader(nullptr, "")
{}

std::pair<std::string, std::string> ls_std::XMLReaderMock::readAttribute(const ls_std::byte_field &_data)
{
  return ls_std::XMLReader::_readAttribute_(_data);
}

std::list<std::pair<std::string, std::string>> ls_std::XMLReaderMock::readAttributes(ls_std::byte_field _data)
{
  return ls_std::XMLReader::_readAttributes_(std::move(_data));
}
