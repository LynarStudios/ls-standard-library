/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-17
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_XML_PARSE_DATA_HPP
#define LS_STD_XML_PARSE_DATA_HPP

#include <cstdint>
#include <memory>
#include "XmlNode.hpp"

namespace ls
{
  namespace std
  {
    namespace io
    {
      struct XmlParseParameter
      {
        uint8_t level{};
        ::std::shared_ptr<ls::std::io::XmlNode> node{};
      };
    }
  }
}

#endif
