/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_KV_PARSER_HPP
#define LS_STD_KV_PARSER_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/base/Types.hpp>
#include "KVDocument.hpp"
#include "KVParseData.hpp"
#include <memory>

namespace ls_std
{
  class KVParser : public ls_std::Class
  {
    public:

      explicit KVParser(const std::shared_ptr<ls_std::KVDocument> &_document);
      ~KVParser() override = default;

      std::shared_ptr<ls_std::KVDocument> getDocument();
      void parse(const ls_std::byte_field &_data);
      void setDocument(const std::shared_ptr<ls_std::KVDocument> &_document);

    private:

      std::shared_ptr<ls_std::KVDocument> document{};

      void _assignDocument(const std::shared_ptr<ls_std::KVDocument> &_document);
      static bool _lineHasPair(ls_std::KVParseData _parseData);
      void _parse(const ls_std::byte_field &_data);
      void _parsePair(ls_std::KVParseData _parseData);
      static ls_std::KVParseData _readLine(const ls_std::byte_field &_data, std::string::size_type _index);
      static void _readLineWithUnixLineBreak(ls_std::KVParseData &_parseData);
      static void _readLineWithWindowsLineBreak(ls_std::KVParseData &_parseData);
  };
}

#endif
