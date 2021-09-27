/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-07-15
 *
 * */

#ifndef LS_STD_KV_FILE_READER_HPP
#define LS_STD_KV_FILE_READER_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/io/IReader.hpp>
#include <ls_std/io/kv/KvDocument.hpp>
#include <ls_std/io/File.hpp>
#include <memory>

namespace ls_std
{
  class KvFileReader : public ls_std::Class, public ls_std::IReader
  {
    public:

      explicit KvFileReader(const std::shared_ptr<ls_std::KvDocument> &_document, const std::string &_absolutePath);
      ~KvFileReader() override = default;

      // implementation

      ls_std::byte_field read() override;

      // additional functionality

      std::shared_ptr<ls_std::KvDocument> getDocument();
      void setDocument(const std::shared_ptr<ls_std::KvDocument> &_document);
      void setFile(const ls_std::File &_kvFile);

    private:

      std::shared_ptr<ls_std::KvDocument> document{};
      ls_std::File kvFile;

      void _assignDocument(const std::shared_ptr<ls_std::KvDocument> &_document);
      void _assignFile(ls_std::File _kvFile);
  };
}

#endif
