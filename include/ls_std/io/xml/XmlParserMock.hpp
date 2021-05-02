/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_XML_PARSER_MOCK_HPP
#define LS_STD_XML_PARSER_MOCK_HPP

#include "XmlParser.hpp"

namespace ls_std
{
  class XmlParserMock : public ls_std::XmlParser
  {
    public:

      XmlParserMock();
      ~XmlParserMock() override = default;

      static std::pair<std::string, std::string> readAttribute(const ls_std::byte_field &_data);
      static std::list<std::pair<std::string, std::string>> readAttributes(ls_std::byte_field _data);
  };
}

#endif
