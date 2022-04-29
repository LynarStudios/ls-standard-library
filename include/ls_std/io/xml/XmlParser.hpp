/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-25
 * Changed:         2022-04-29
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

namespace ls_std
{
  class XmlParser : public ls_std::Class
  {
    public:

      explicit XmlParser(const std::shared_ptr<ls_std::XmlDocument> &_document);
      ~XmlParser() override = default;

      std::shared_ptr<ls_std::XmlDocument> getDocument();
      void parse(const ls_std::byte_field &_data);
      void setDocument(const std::shared_ptr<ls_std::XmlDocument> &_document);

    protected:

      static std::pair<std::string, std::string> _readAttribute_(const ls_std::byte_field &_data);
      static std::list<std::pair<std::string, std::string>> _readAttributes_(ls_std::byte_field _data);

    private:

      uint8_t currentLevel{};
      std::shared_ptr<ls_std::XmlDocument> document{};
      uint8_t maxLevel{};
      ls_std::XmlParseMode mode{};
      std::list<ls_std::XmlParseParameter> parseParameters{};

      void _analyze(const ls_std::byte_field &_data, std::string::size_type _index);
      void _assignDocument(const std::shared_ptr<ls_std::XmlDocument> &_document);
      static std::shared_ptr<ls_std::XmlDeclaration> _createDeclaration(const std::list<std::pair<std::string, std::string>> &_attributes);
      static std::shared_ptr<ls_std::XmlNode> _createNode(const std::list<std::pair<std::string, std::string>> &_attributes, const std::string &_name);
      static std::pair<std::string, std::string> _findAttribute(const std::list<std::pair<std::string, std::string>> &_attributes, const std::string &_name);
      static size_t _findAttributeEndPosition(const ls_std::byte_field &_data);
      static ls_std::byte_field _getNextTagString(const ls_std::byte_field &_data, std::string::size_type _index);
      void _isClosingTag(const ls_std::byte_field &_data, std::string::size_type _index);
      void _isDeclaration(const ls_std::byte_field &_data, std::string::size_type _index);
      void _isOpeningTag(const ls_std::byte_field &_data, std::string::size_type _index);
      void _isValue(const ls_std::byte_field &_data, std::string::size_type _index);
      void _mergeNodes();
      void _mergeChildrenToParentNode(const std::shared_ptr<ls_std::XmlNode> &_parent, std::list<ls_std::XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel);
      void _mergeNodesOnCurrentLevel();
      void _parse(const ls_std::byte_field &_data);
      static std::pair<std::string, std::string> _parseAttribute(const ls_std::byte_field &_data);
      static std::list<std::pair<std::string, std::string>> _parseAttributes(ls_std::byte_field _data);
      size_t _parseClosingTag(const ls_std::byte_field &_data, std::string::size_type _index);
      size_t _parseDeclaration(const ls_std::byte_field &_data, std::string::size_type _index);
      size_t _parseOpeningTag(const ls_std::byte_field &_data, std::string::size_type _index);
      static ls_std::byte_field _parseTagName(const ls_std::byte_field &_data);
      size_t _parseValue(const ls_std::byte_field &_data, std::string::size_type _index);
      void _reset();
      void _setMaxLevel();
  };
}

#endif
