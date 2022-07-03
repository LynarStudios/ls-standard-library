/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-07-03
 *
 * */

#ifndef LS_STD_KV_PARSER_HPP
#define LS_STD_KV_PARSER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/core/types/Types.hpp>
#include "KvDocument.hpp"
#include "KvParseParameter.hpp"
#include <memory>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvParser : public ls::std::core::Class
  {
    public:

      explicit KvParser(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
      ~KvParser() override = default;

      ::std::shared_ptr<ls::std::io::KvDocument> getDocument();
      void parse(const ls::std::core::type::byte_field &_data);
      void setDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);

    private:

      ::std::shared_ptr<ls::std::io::KvDocument> document{};

      void _assignDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document);
      static bool _contains(const ::std::string &_text, const ::std::string &_searchText);
      static bool _lineHasPair(const ls::std::io::KvParseParameter &_parseParameter);
      void _parse(const ls::std::core::type::byte_field &_data);
      void _parsePair(const ls::std::io::KvParseParameter &_parseParameter);
      static ls::std::io::KvParseParameter _readLine(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      static void _readLineWithUnixLineBreak(ls::std::io::KvParseParameter &_parseParameter);
      static void _readLineWithWindowsLineBreak(ls::std::io::KvParseParameter &_parseParameter);
  };
}

#endif
