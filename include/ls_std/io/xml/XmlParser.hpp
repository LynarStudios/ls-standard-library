/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-25
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_XML_PARSER_HPP
#define LS_STD_XML_PARSER_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/core/Types.hpp>
#include "XmlDocument.hpp"
#include "XmlParseMode.hpp"
#include "XmlParseParameter.hpp"
#include <list>

namespace ls
{
  class XmlParser : public ls::std::core::Class
  {
    public:

      explicit XmlParser(const ::std::shared_ptr<ls::XmlDocument> &_document);
      ~XmlParser() override = default;

      ::std::shared_ptr<ls::XmlDocument> getDocument();
      void parse(const ls::std::core::byte_field &_data);
      void setDocument(const ::std::shared_ptr<ls::XmlDocument> &_document);

    protected:

      static ::std::pair<::std::string, ::std::string> _readAttribute_(const ls::std::core::byte_field &_data);
      static ::std::list<::std::pair<::std::string, ::std::string>> _readAttributes_(ls::std::core::byte_field _data);

    private:

      uint8_t currentLevel{};
      ::std::shared_ptr<ls::XmlDocument> document{};
      uint8_t maxLevel{};
      ls::XmlParseMode mode{};
      ::std::list<ls::XmlParseParameter> parseParameters{};

      void _analyze(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _assignDocument(const ::std::shared_ptr<ls::XmlDocument> &_document);
      static ::std::shared_ptr<ls::XmlDeclaration> _createDeclaration(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes);
      static ::std::shared_ptr<ls::XmlNode> _createNode(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name);
      static ::std::pair<::std::string, ::std::string> _findAttribute(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name);
      static size_t _findAttributeEndPosition(const ls::std::core::byte_field &_data);
      static ls::std::core::byte_field _getNextTagString(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _isClosingTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _isDeclaration(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _isOpeningTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _isValue(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _mergeNodes();
      void _mergeChildrenToParentNode(const ::std::shared_ptr<ls::XmlNode> &_parent, ::std::list<ls::XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel);
      void _mergeNodesOnCurrentLevel();
      void _parse(const ls::std::core::byte_field &_data);
      static ::std::pair<::std::string, ::std::string> _parseAttribute(const ls::std::core::byte_field &_data);
      static ::std::list<::std::pair<::std::string, ::std::string>> _parseAttributes(ls::std::core::byte_field _data);
      size_t _parseClosingTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      size_t _parseDeclaration(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      size_t _parseOpeningTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      static ls::std::core::byte_field _parseTagName(const ls::std::core::byte_field &_data);
      size_t _parseValue(const ls::std::core::byte_field &_data, ::std::string::size_type _index);
      void _reset();
      void _setMaxLevel();
  };
}

#endif
