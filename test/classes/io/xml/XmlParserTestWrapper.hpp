/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_XML_PARSER_MOCK_HPP
#define LS_STD_XML_PARSER_MOCK_HPP

#include <ls-std/ls-std-io.hpp>

namespace test::io
{
  class XmlParserTestWrapper : public ls::std::io::XmlParser
  {
    public:

      XmlParserTestWrapper();
      ~XmlParserTestWrapper() override;

      static ::std::pair<::std::string, ::std::string> readAttribute(const ls::std::core::type::byte_field &_data);
      static ::std::list<::std::pair<::std::string, ::std::string>> readAttributes(ls::std::core::type::byte_field _data);
  };
}

#endif
