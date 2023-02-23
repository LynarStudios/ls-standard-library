/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlParser.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::XmlAttribute;
using ls::std::io::XmlDeclaration;
using ls::std::io::XmlDocument;
using ls::std::io::XmlNode;
using ls::std::io::XmlParseMode;
using ls::std::io::XmlParseParameter;
using ls::std::io::XmlParser;
using std::list;
using std::make_shared;
using std::move;
using std::pair;
using std::shared_ptr;
using std::string;

XmlParser::XmlParser(const shared_ptr<XmlDocument> &_document) : Class("XmlParser")
{
  this->_assignDocument(_document);
  this->_reset();
}

XmlParser::~XmlParser() noexcept = default;

shared_ptr<XmlDocument> XmlParser::getDocument()
{
  return this->document;
}

void XmlParser::parse(const byte_field &_data)
{
  this->_parse(_data);
  this->_mergeNodes();
  this->_reset();
}

void XmlParser::setDocument(const shared_ptr<XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

pair<string, string> XmlParser::_readAttribute_(const byte_field &_data)
{
  return XmlParser::_parseAttribute(_data);
}

list<pair<string, string>> XmlParser::_readAttributes_(byte_field _data)
{
  return XmlParser::_parseAttributes(::move(_data));
}

void XmlParser::_analyze(const byte_field &_data, string::size_type _index)
{
  this->_isDeclaration(_data, _index);
  this->_isClosingTag(_data, _index);
  this->_isOpeningTag(_data, _index);
  this->_isValue(_data, _index);
}

void XmlParser::_assignDocument(const shared_ptr<XmlDocument> &_document)
{
  NullPointerArgumentEvaluator{_document, "passed document reference is null!"}.evaluate();
  this->document = _document;
}

bool XmlParser::_contains(const string &_text, const string &_searchText)
{
  return _text.find(_searchText) != string::npos;
}

shared_ptr<XmlDeclaration> XmlParser::_createDeclaration(const list<pair<string, string>> &_attributes)
{
  shared_ptr<XmlDeclaration> declaration = make_shared<XmlDeclaration>("1.0");
  pair<string, string> attribute = XmlParser::_findAttribute(_attributes, "version");

  if (!attribute.first.empty())
  {
    declaration->setVersion(attribute.second);
  }

  attribute = XmlParser::_findAttribute(_attributes, "encoding");

  if (!attribute.first.empty())
  {
    declaration->setEncoding(attribute.second);
  }

  attribute = XmlParser::_findAttribute(_attributes, "standalone");

  if (!attribute.first.empty())
  {
    declaration->setStandalone(attribute.second);
  }

  return declaration;
}

shared_ptr<XmlNode> XmlParser::_createNode(const list<pair<string, string>> &_attributes, const string &_name)
{
  shared_ptr<XmlNode> node = make_shared<XmlNode>(_name);
  shared_ptr<XmlAttribute> attribute{};

  for (const auto &parsedAttribute : _attributes)
  {
    attribute = make_shared<XmlAttribute>(parsedAttribute.first);
    attribute->setValue(parsedAttribute.second);
    node->addAttributeToEnd(attribute);
  }

  return node;
}

bool XmlParser::_endsWith(const string &_text, const string &_ending)
{
  return _text.rfind(_ending) == (_text.size() - _ending.size());
}

pair<string, string> XmlParser::_findAttribute(const list<pair<string, string>> &_attributes, const string &_name)
{
  pair<string, string> attribute{};

  for (const auto &currentAttribute : _attributes)
  {
    if (currentAttribute.first == _name)
    {
      attribute = currentAttribute;
      break;
    }
  }

  return attribute;
}

size_t XmlParser::_findAttributeEndPosition(const byte_field &_data)
{
  string::size_type position = string::npos;
  string::size_type counter{};

  for (char letter : _data)
  {
    if (letter == '"')
    {
      counter++;
    }

    if (counter == 2)
    {
      break;
    }

    position++;
  }

  return position;
}

byte_field XmlParser::_getNextTagString(const byte_field &_data, string::size_type _index)
{
  byte_field tag{};
  size_t closingCharacterPosition = _index + _data.substr(_index).find('>');

  if (closingCharacterPosition != string::npos)
  {
    tag = _data.substr(_index, (closingCharacterPosition - _index) + 1);
  }

  return tag;
}

void XmlParser::_isClosingTag(const byte_field &_data, string::size_type _index)
{
  if (this->mode == XmlParseMode::XML_PARSE_MODE_ANALYZE && _data.substr(_index, 2) == "</")
  {
    this->mode = XmlParseMode::XML_PARSE_MODE_CLOSING_TAG;
  }
}

void XmlParser::_isDeclaration(const byte_field &_data, string::size_type _index)
{
  if (_data.substr(_index, 5) == "<?xml")
  {
    this->mode = XmlParseMode::XML_PARSE_MODE_DECLARATION;
  }
}

void XmlParser::_isOpeningTag(const byte_field &_data, string::size_type _index)
{
  if (this->mode == XmlParseMode::XML_PARSE_MODE_ANALYZE && _data.substr(_index, 1) == "<")
  {
    this->mode = XmlParseMode::XML_PARSE_MODE_OPENING_TAG;
  }
}

void XmlParser::_isValue(const byte_field &_data, string::size_type _index)
{
  if (this->mode == XmlParseMode::XML_PARSE_MODE_ANALYZE)
  {
    string::size_type end = _data.substr(_index).find('<');
    bool isValue = _data[_index - 1] == '>' && end != string::npos && end > 0;

    if (isValue)
    {
      string value{_data.substr(_index, end)};

      if (!XmlParser::_contains(value, "\n") && !XmlParser::_contains(value, "\r\n"))
      {
        this->mode = XmlParseMode::XML_PARSE_MODE_VALUE;
      }
    }
  }
}

void XmlParser::_mergeNodes()
{
  while (this->maxLevel > 1)
  {
    this->_mergeNodesOnCurrentLevel();
    this->maxLevel -= 1;
  }

  this->document->setRootElement(this->parseParameters.front().getNode());
}

void XmlParser::_mergeChildrenToParentNode(const shared_ptr<XmlNode> &_parent, list<XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel)
{
  do
  {
    _iterator++;

    if (_iterator == this->parseParameters.end())
    {
      break;
    }
    else
    {
      if (_iterator->getLevel() == this->maxLevel)
      {
        _parent->addChildToEnd(_iterator->getNode());
      }
    }
  } while (_iterator->getLevel() > _parentLevel);
}

void XmlParser::_mergeNodesOnCurrentLevel()
{
  auto iterator = this->parseParameters.begin();
  uint8_t parentLevel = this->maxLevel - 1;

  while (iterator != this->parseParameters.end())
  {
    if (iterator->getLevel() == parentLevel)
    {
      this->_mergeChildrenToParentNode(iterator->getNode(), iterator, parentLevel);
    }
    else
    {
      iterator++;
    }
  }
}

void XmlParser::_parse(const byte_field &_data)
{
  for (string::size_type index = 0; index < _data.size(); index++)
  {
    switch (this->mode)
    {
      case XmlParseMode::XML_PARSE_MODE_ANALYZE:
      {
        this->_analyze(_data, index);
      }
      break;
      case XmlParseMode::XML_PARSE_MODE_DECLARATION:
      {
        --index;
        index = this->_parseDeclaration(_data, index);
        this->mode = XmlParseMode::XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XmlParseMode::XML_PARSE_MODE_OPENING_TAG:
      {
        --index;
        index = XmlParser::_parseOpeningTag(_data, index);
        this->mode = XmlParseMode::XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XmlParseMode::XML_PARSE_MODE_VALUE:
      {
        --index;
        index = XmlParser::_parseValue(_data, index);
        this->mode = XmlParseMode::XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XmlParseMode::XML_PARSE_MODE_CLOSING_TAG:
      {
        --index;
        index = XmlParser::_parseClosingTag(_data, index);
        this->mode = XmlParseMode::XML_PARSE_MODE_ANALYZE;
      }
      break;
    }
  }
}

pair<string, string> XmlParser::_parseAttribute(const byte_field &_data)
{
  pair<string, string> parsedAttribute{};
  parsedAttribute.first = _data.substr(0, _data.find('='));
  parsedAttribute.second = _data.substr(_data.find('"') + 1);
  parsedAttribute.second.pop_back();

  return parsedAttribute;
}

list<pair<string, string>> XmlParser::_parseAttributes(byte_field _data)
{
  list<pair<string, string>> attributes{};
  size_t position = _data.find(' ');
  _data = position == string::npos ? "" : _data.substr(position);

  while (!_data.empty())
  {
    do
    {
      position = _data.find(' ') + 1;
    } while (_data[position] == ' ');

    if (_data.size() <= 3 && XmlParser::_endsWith(string{_data}, ">"))
    {
      break;
    }

    string attributeString = _data.substr(position, XmlParser::_findAttributeEndPosition(_data) + 1);
    attributes.push_back(XmlParser::_parseAttribute(attributeString));
    _data = _data.substr(position + attributeString.size());
  }

  return attributes;
}

size_t XmlParser::_parseClosingTag(const byte_field &_data, string::size_type _index)
{
  string tagString = XmlParser::_getNextTagString(_data, _index);
  this->currentLevel -= 1;
  return tagString.empty() ? _index : _index + (tagString.size() - 1);
}

size_t XmlParser::_parseDeclaration(const byte_field &_data, string::size_type _index)
{
  string tagString = XmlParser::_getNextTagString(_data, _index);
  bool isValidTagString = !tagString.empty();

  if (isValidTagString)
  {
    shared_ptr<XmlDeclaration> declaration = this->_createDeclaration(XmlParser::_parseAttributes(tagString));
    this->document->setDeclaration(declaration);
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

size_t XmlParser::_parseOpeningTag(const byte_field &_data, string::size_type _index)
{
  string tagString{XmlParser::_getNextTagString(_data, _index)};
  bool isValidTagString = !tagString.empty();
  XmlParseParameter singleParseParameter{};

  if (isValidTagString)
  {
    shared_ptr<XmlNode> node = XmlParser::_createNode(XmlParser::_parseAttributes(tagString), XmlParser::_parseTagName(tagString));

    singleParseParameter.setLevel(this->currentLevel);
    singleParseParameter.setNode(node);
    this->parseParameters.push_back(singleParseParameter);

    if (!XmlParser::_endsWith(tagString, "/>"))
    {
      this->currentLevel += 1;
      this->_setMaxLevel();
    }
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

byte_field XmlParser::_parseTagName(const byte_field &_data)
{
  string::size_type position = _data.find(' ');

  if (position == string::npos)
  {
    position = _data.find('>');
  }

  return _data.substr(1, position - 1);
}

size_t XmlParser::_parseValue(const byte_field &_data, string::size_type _index)
{
  byte_field value = _data.substr(_index, _data.substr(_index).find('<'));
  this->parseParameters.back().getNode()->setValue(value);

  return _index + (value.size() - 1);
}

void XmlParser::_reset()
{
  this->currentLevel = 1;
  this->maxLevel = 1;
  this->mode = XmlParseMode::XML_PARSE_MODE_ANALYZE;
  this->parseParameters.clear();
}

void XmlParser::_setMaxLevel()
{
  if (this->currentLevel > this->maxLevel)
  {
    this->maxLevel = this->currentLevel;
  }
}
