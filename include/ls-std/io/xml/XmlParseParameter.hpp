/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-17
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_XML_PARSE_DATA_HPP
#define LS_STD_XML_PARSE_DATA_HPP

#include "XmlNode.hpp"
#include <cstdint>
#include <memory>

namespace ls::std::io
{
  struct XmlParseParameter
  {
    public:

      uint8_t level{};
      ::std::shared_ptr<ls::std::io::XmlNode> node{};
  };
}

#endif
