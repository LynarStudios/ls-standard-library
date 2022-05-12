/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_KV_FILE_READER_HPP
#define LS_STD_KV_FILE_READER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/core/interface/IReader.hpp>
#include <ls_std/io/kv/KvDocument.hpp>
#include <ls_std/io/File.hpp>
#include <memory>

namespace ls
{
  namespace std
  {
    namespace io
    {
      class KvFileReader : public ls::std::core::Class, public ls::std::core::IReader
      {
        public:

          explicit KvFileReader(const ::std::shared_ptr<ls::std::io::KvDocument> &_document, const ::std::string &_absolutePath);
          ~KvFileReader() override = default;

          // implementation

          ls::std::core::type::byte_field read() override;

          // additional functionality

          ::std::shared_ptr<ls::std::io::KvDocument> getDocument();
          void setDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
          void setFile(const ls::std::io::File &_kvFile);

        private:

          ::std::shared_ptr<ls::std::io::KvDocument> document{};
          ls::std::io::File kvFile;

          void _assignDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
          void _assignFile(ls::std::io::File _kvFile);
      };
    }
  }
}

#endif
