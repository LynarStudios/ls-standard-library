/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include <ls-std/core/Class.hpp>
#include "XmlDocument.hpp"
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/io/File.hpp>
#include "XmlParseMode.hpp"
#include "XmlParseParameter.hpp"
#include <list>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlReader : public ls::std::core::Class, public ls::std::core::interface_type::IReader
  {
    public:

      explicit XmlReader(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document, const ::std::string &_absolutePath);
      ~XmlReader() override = default;

      // implementation

      ls::std::core::type::byte_field read() override;

      // additional functionality

      ::std::shared_ptr<ls::std::io::XmlDocument> getDocument();
      void setDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document);
      void setFile(const ls::std::io::File &_xmlFile);

    private:

      ::std::shared_ptr<ls::std::io::XmlDocument> document{};
      ls::std::io::File xmlFile;

      void _assignDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document);
      void _assignFile(ls::std::io::File _xmlFile);
  };
}

#endif
