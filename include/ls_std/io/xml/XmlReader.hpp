/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include <ls_std/core/Class.hpp>
#include "XmlDocument.hpp"
#include <ls_std/io/IReader.hpp>
#include <ls_std/io/File.hpp>
#include "XmlParseMode.hpp"
#include "XmlParseParameter.hpp"
#include <list>

namespace ls
{
  class XmlReader : public ls::Class, public ls::IReader
  {
    public:

      explicit XmlReader(const ::std::shared_ptr<ls::XmlDocument> &_document, const ::std::string &_absolutePath);
      ~XmlReader() override = default;

      // implementation

      ls::byte_field read() override;

      // additional functionality

      ::std::shared_ptr<ls::XmlDocument> getDocument();
      void setDocument(const ::std::shared_ptr<ls::XmlDocument> &_document);
      void setFile(const ls::File &_xmlFile);

    private:

      ::std::shared_ptr<ls::XmlDocument> document{};
      ls::File xmlFile;

      void _assignDocument(const ::std::shared_ptr<ls::XmlDocument> &_document);
      void _assignFile(ls::File _xmlFile);
  };
}

#endif
