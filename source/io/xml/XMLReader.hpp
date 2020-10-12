/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2020-10-10
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include "../../base/Class.hpp"
#include "XMLDocument.hpp"
#include "../IReader.hpp"
#include "../File.hpp"

namespace ls_std {
  class XMLReader : public Class, IReader {
    public:

      explicit XMLReader(const std::shared_ptr<ls_std::XMLDocument>& _document, const std::string& _absolutePath);
      ~XMLReader() = default;

      // implementation

      ls_std::byte_field read() override;

      // additional functionality

      std::shared_ptr<ls_std::XMLDocument> getDocument();
      void setFile(const ls_std::File& _xmlFile);

    private:

      std::shared_ptr<ls_std::XMLDocument> document {};
      ls_std::File xmlFile;

      static void _checkDocumentExistence(const std::shared_ptr<ls_std::XMLDocument>& _document);
      static void _checkFileExistence(ls_std::File _xmlFile);
      void _read(const ls_std::byte_field& _data);
  };
}

#endif
