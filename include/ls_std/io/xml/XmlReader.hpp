/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-08
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_XML_READER_HPP
#define LS_STD_XML_READER_HPP

#include <ls_std/core/Class.hpp>
#include "XmlDocument.hpp"
#include <ls_std/core/interface/IReader.hpp>
#include <ls_std/io/File.hpp>
#include "XmlParseMode.hpp"
#include "XmlParseParameter.hpp"
#include <list>

namespace ls
{
  namespace std
  {
    namespace io
    {
      class XmlReader : public ls::std::core::Class, public ls::std::core::IReader
      {
        public:

          explicit XmlReader(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document, const ::std::string &_absolutePath);
          ~XmlReader() override = default;

          // implementation

          ls::std::core::byte_field read() override;

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
  }
}

#endif
