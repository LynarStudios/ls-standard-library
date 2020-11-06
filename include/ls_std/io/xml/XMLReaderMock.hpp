/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-18
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_XML_READER_MOCK_HPP
#define LS_STD_XML_READER_MOCK_HPP

#include "XMLReader.hpp"

namespace ls_std {
  class XMLReaderMock : public XMLReader {
    public:

      XMLReaderMock();
      ~XMLReaderMock() = default;

      static std::pair<std::string, std::string> readAttribute(const ls_std::byte_field &_data);
      static std::list<std::pair<std::string, std::string>> readAttributes(ls_std::byte_field _data);
  };
}

#endif
