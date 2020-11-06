/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-13
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_XML_PARSE_MODE_HPP
#define LS_STD_XML_PARSE_MODE_HPP

namespace ls_std {
  enum XMLParseMode {
    XML_PARSE_MODE_ANALYZE = 0,
    XML_PARSE_MODE_DECLARATION,
    XML_PARSE_MODE_OPENING_TAG,
    XML_PARSE_MODE_VALUE,
    XML_PARSE_MODE_CLOSING_TAG
  };
}

#endif
