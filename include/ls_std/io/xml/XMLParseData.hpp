/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-17
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_XML_PARSE_DATA_HPP
#define LS_STD_XML_PARSE_DATA_HPP

#include <cstdint>
#include <memory>
#include "XMLNode.hpp"

namespace ls_std {
  struct XMLParseData {
    uint8_t level {};
    std::shared_ptr<ls_std::XMLNode> node {};
  };
}

#endif
