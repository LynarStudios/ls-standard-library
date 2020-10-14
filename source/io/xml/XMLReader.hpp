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
#include "XMLParseMode.hpp"
#include <unordered_map>

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
      ls_std::XMLParseMode mode {};
      ls_std::File xmlFile;

      static void _checkDocumentExistence(const std::shared_ptr<ls_std::XMLDocument>& _document);
      static void _checkFileExistence(ls_std::File _xmlFile);
      static std::shared_ptr<ls_std::XMLDeclaration> _createDeclaration(const std::unordered_map<std::string, std::string>& _attributes);
      void _isClosingTag(const ls_std::byte_field& _data, std::string::size_type _index);
      void _isDeclaration(const ls_std::byte_field& _data, std::string::size_type _index);
      void _isOpeningTag(const ls_std::byte_field& _data, std::string::size_type _index);
      void _read(const ls_std::byte_field& _data);
      static std::pair<std::string, std::string> _readAttribute(const ls_std::byte_field& _data);
      static std::unordered_map<std::string, std::string> _readAttributes(ls_std::byte_field _data);
      size_t _readDeclaration(const ls_std::byte_field& _data, std::string::size_type _index);
  };
}

#endif
