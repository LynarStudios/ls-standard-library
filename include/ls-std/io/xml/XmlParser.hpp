/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-25
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_XML_PARSER_HPP
#define LS_STD_XML_PARSER_HPP

#include "XmlDocument.hpp"
#include "XmlParseMode.hpp"
#include "XmlParseParameter.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/core/type/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlParser : public ls::std::core::Class
  {
    public:

      explicit XmlParser(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document);
      ~XmlParser() noexcept override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::XmlDocument> getDocument();
      void parse(const ls::std::core::type::byte_field &_data);
      void setDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document);

    protected:

      [[nodiscard]] static ::std::pair<::std::string, ::std::string> _readAttribute_(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ::std::list<::std::pair<::std::string, ::std::string>> _readAttributes_(ls::std::core::type::byte_field _data);

    private:

      uint8_t currentLevel{};
      ::std::shared_ptr<ls::std::io::XmlDocument> document{};
      uint8_t maxLevel{};
      ls::std::io::XmlParseMode mode{};
      ::std::list<ls::std::io::XmlParseParameter> parseParameters{};

      void _analyze(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _assignDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document);
      [[nodiscard]] static bool _contains(const ::std::string &_text, const ::std::string &_searchText);
      [[nodiscard]] static ::std::shared_ptr<ls::std::io::XmlDeclaration> _createDeclaration(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes);
      [[nodiscard]] static ::std::shared_ptr<ls::std::io::XmlNode> _createNode(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name);
      [[nodiscard]] static bool _endsWith(const ::std::string &_text, const ::std::string &_ending);
      [[nodiscard]] static ::std::pair<::std::string, ::std::string> _findAttribute(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name);
      [[nodiscard]] static size_t _findAttributeEndPosition(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ls::std::core::type::byte_field _getNextTagString(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _isClosingTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _isDeclaration(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _isOpeningTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _isValue(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _mergeNodes();
      void _mergeChildrenToParentNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_parent, ::std::list<ls::std::io::XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel);
      void _mergeNodesOnCurrentLevel();
      void _parse(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ::std::pair<::std::string, ::std::string> _parseAttribute(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] static ::std::list<::std::pair<::std::string, ::std::string>> _parseAttributes(ls::std::core::type::byte_field _data);
      [[nodiscard]] size_t _parseClosingTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      [[nodiscard]] size_t _parseDeclaration(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      [[nodiscard]] size_t _parseOpeningTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      [[nodiscard]] static ls::std::core::type::byte_field _parseTagName(const ls::std::core::type::byte_field &_data);
      [[nodiscard]] size_t _parseValue(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index);
      void _reset();
      void _setMaxLevel();
  };
}

#endif
