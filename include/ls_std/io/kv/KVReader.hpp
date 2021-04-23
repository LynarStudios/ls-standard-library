/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_KV_READER_HPP
#define LS_STD_KV_READER_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/io/IReader.hpp>
#include <ls_std/io/kv/KVDocument.hpp>
#include <ls_std/io/File.hpp>
#include <memory>

namespace ls_std
{
  class KVReader : public ls_std::Class, public ls_std::IReader
  {
    public:

      explicit KVReader(const std::shared_ptr<ls_std::KVDocument> &_document, const std::string &_absolutePath);
      ~KVReader() override = default;

      // implementation

      ls_std::byte_field read() override;

      // additional functionality

      std::shared_ptr<ls_std::KVDocument> getDocument();
      void setDocument(const std::shared_ptr<ls_std::KVDocument> &_document);
      void setFile(const ls_std::File &_kvFile);

    private:

      std::shared_ptr<ls_std::KVDocument> document{};
      ls_std::File kvFile;

      void _assignDocument(const std::shared_ptr<ls_std::KVDocument> &_document);
      void _assignFile(ls_std::File _kvFile);
  };
}

#endif
