/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2020-10-08
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include "../../base/Class.hpp"
#include "XMLDocument.hpp"
#include "../IReader.hpp"

namespace ls_std {
  class XMLReader : public Class, IReader {
    public:

      explicit XMLReader(std::shared_ptr<ls_std::XMLDocument> _document, std::string _path);
      ~XMLReader() = default;

      // implementation

      ls_std::byte_field read() override;

    private:

      std::shared_ptr<ls_std::XMLDocument> document {};
      std::string path {};
  };
}

#endif
