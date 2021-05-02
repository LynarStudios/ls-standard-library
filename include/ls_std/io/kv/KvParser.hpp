/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_KV_PARSER_HPP
#define LS_STD_KV_PARSER_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/base/Types.hpp>
#include "KvDocument.hpp"
#include "KvParseParameter.hpp"
#include <memory>

namespace ls_std
{
  class KvParser : public ls_std::Class
  {
    public:

      explicit KvParser(const std::shared_ptr<ls_std::KvDocument> &_document);
      ~KvParser() override = default;

      std::shared_ptr<ls_std::KvDocument> getDocument();
      void parse(const ls_std::byte_field &_data);
      void setDocument(const std::shared_ptr<ls_std::KvDocument> &_document);

    private:

      std::shared_ptr<ls_std::KvDocument> document{};

      void _assignDocument(const std::shared_ptr<ls_std::KvDocument> &_document);
      static bool _lineHasPair(ls_std::KvParseParameter _parseParameter);
      void _parse(const ls_std::byte_field &_data);
      void _parsePair(ls_std::KvParseParameter _parseParameter);
      static ls_std::KvParseParameter _readLine(const ls_std::byte_field &_data, std::string::size_type _index);
      static void _readLineWithUnixLineBreak(ls_std::KvParseParameter &_parseParameter);
      static void _readLineWithWindowsLineBreak(ls_std::KvParseParameter &_parseParameter);
  };
}

#endif
