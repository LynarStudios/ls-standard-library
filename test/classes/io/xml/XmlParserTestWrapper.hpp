/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2023-03-27
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
      ~XmlParserTestWrapper() noexcept override;

      [[nodiscard]] static ::std::pair<::std::string, ::std::string> readAttribute(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ::std::list<::std::pair<::std::string, ::std::string>> readAttributes(ls::std::core::type::byte_field _data);
  };
}

#endif
