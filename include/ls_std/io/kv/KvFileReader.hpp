/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_KV_FILE_READER_HPP
#define LS_STD_KV_FILE_READER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/io/IReader.hpp>
#include <ls_std/io/kv/KvDocument.hpp>
#include <ls_std/io/File.hpp>
#include <memory>

namespace ls
{
  class KvFileReader : public ls::Class, public ls::IReader
  {
    public:

      explicit KvFileReader(const ::std::shared_ptr<ls::KvDocument> &_document, const ::std::string &_absolutePath);
      ~KvFileReader() override = default;

      // implementation

      ls::byte_field read() override;

      // additional functionality

      ::std::shared_ptr<ls::KvDocument> getDocument();
      void setDocument(const ::std::shared_ptr<ls::KvDocument> &_document);
      void setFile(const ls::File &_kvFile);

    private:

      ::std::shared_ptr<ls::KvDocument> document{};
      ls::File kvFile;

      void _assignDocument(const ::std::shared_ptr<ls::KvDocument> &_document);
      void _assignFile(ls::File _kvFile);
  };
}

#endif
