/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include <ls_std/base/Class.hpp>
#include "XMLDocument.hpp"
#include <ls_std/io/IReader.hpp>
#include <ls_std/io/File.hpp>
#include "XMLParseMode.hpp"
#include "XMLParseData.hpp"
#include <list>

namespace ls_std
{
  class XMLReader : public ls_std::Class, public ls_std::IReader
  {
    public:

      explicit XMLReader(const std::shared_ptr<ls_std::XMLDocument> &_document, const std::string &_absolutePath);
      ~XMLReader() override = default;

      // implementation

      ls_std::byte_field read() override;

      // additional functionality

      std::shared_ptr<ls_std::XMLDocument> getDocument();
      void setDocument(const std::shared_ptr<ls_std::XMLDocument> &_document);
      void setFile(const ls_std::File &_xmlFile);

    private:

      std::shared_ptr<ls_std::XMLDocument> document{};
      ls_std::File xmlFile;

      void _assignDocument(const std::shared_ptr<ls_std::XMLDocument> &_document);
      void _assignFile(ls_std::File _xmlFile);
  };
}

#endif
