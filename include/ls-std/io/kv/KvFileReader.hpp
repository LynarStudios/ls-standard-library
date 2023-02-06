/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_KV_FILE_READER_HPP
#define LS_STD_KV_FILE_READER_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/io/File.hpp>
#include <ls-std/io/kv/KvDocument.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvFileReader : public ls::std::core::Class, public ls::std::core::interface_type::IReader
  {
    public:

      explicit KvFileReader(const ::std::shared_ptr<ls::std::io::KvDocument> &_document, const ::std::string &_absolutePath);
      ~KvFileReader() override;

      // implementation

      ls::std::core::type::byte_field read() override; // nodiscard is optional here

      // additional functionality

      [[nodiscard]] ::std::shared_ptr<ls::std::io::KvDocument> getDocument();
      void setDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
      void setFile(const ls::std::io::File &_kvFile);

    private:

      ::std::shared_ptr<ls::std::io::KvDocument> document{};
      ls::std::io::File kvFile;

      void _assignDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
      void _assignFile(ls::std::io::File _kvFile);
  };
}

#endif
