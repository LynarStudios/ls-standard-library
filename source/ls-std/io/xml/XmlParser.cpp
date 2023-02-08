/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlParser.hpp>

ls::std::io::XmlParser::XmlParser(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document) : ls::std::core::Class("XmlParser")
{
  this->_assignDocument(_document);
  this->_reset();
}

ls::std::io::XmlParser::~XmlParser() = default;

::std::shared_ptr<ls::std::io::XmlDocument> ls::std::io::XmlParser::getDocument()
{
  return this->document;
}

void ls::std::io::XmlParser::parse(const ls::std::core::type::byte_field &_data)
{
  this->_parse(_data);
  this->_mergeNodes();
  this->_reset();
}

void ls::std::io::XmlParser::setDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

::std::pair<::std::string, ::std::string> ls::std::io::XmlParser::_readAttribute_(const ls::std::core::type::byte_field &_data)
{
  return ls::std::io::XmlParser::_parseAttribute(_data);
}

::std::list<::std::pair<::std::string, ::std::string>> ls::std::io::XmlParser::_readAttributes_(ls::std::core::type::byte_field _data)
{
  return ls::std::io::XmlParser::_parseAttributes(::std::move(_data));
}

void ls::std::io::XmlParser::_analyze(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  this->_isDeclaration(_data, _index);
  this->_isClosingTag(_data, _index);
  this->_isOpeningTag(_data, _index);
  this->_isValue(_data, _index);
}

void ls::std::io::XmlParser::_assignDocument(const ::std::shared_ptr<ls::std::io::XmlDocument> &_document)
{
  ls::std::core::NullPointerArgumentEvaluator{_document, "passed document reference is null!"}.evaluate();
  this->document = _document;
}

bool ls::std::io::XmlParser::_contains(const ::std::string &_text, const ::std::string &_searchText)
{
  return _text.find(_searchText) != ::std::string::npos;
}

::std::shared_ptr<ls::std::io::XmlDeclaration> ls::std::io::XmlParser::_createDeclaration(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes)
{
  ::std::shared_ptr<ls::std::io::XmlDeclaration> declaration = ::std::make_shared<ls::std::io::XmlDeclaration>("1.0");
  ::std::pair<::std::string, ::std::string> attribute = ls::std::io::XmlParser::_findAttribute(_attributes, "version");

  if (!attribute.first.empty())
  {
    declaration->setVersion(attribute.second);
  }

  attribute = ls::std::io::XmlParser::_findAttribute(_attributes, "encoding");

  if (!attribute.first.empty())
  {
    declaration->setEncoding(attribute.second);
  }

  attribute = ls::std::io::XmlParser::_findAttribute(_attributes, "standalone");

  if (!attribute.first.empty())
  {
    declaration->setStandalone(attribute.second);
  }

  return declaration;
}

::std::shared_ptr<ls::std::io::XmlNode> ls::std::io::XmlParser::_createNode(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name)
{
  ::std::shared_ptr<ls::std::io::XmlNode> node = ::std::make_shared<ls::std::io::XmlNode>(_name);
  ::std::shared_ptr<ls::std::io::XmlAttribute> attribute{};

  for (const auto &parsedAttribute : _attributes)
  {
    attribute = ::std::make_shared<ls::std::io::XmlAttribute>(parsedAttribute.first);
    attribute->setValue(parsedAttribute.second);
    node->addAttributeToEnd(attribute);
  }

  return node;
}

bool ls::std::io::XmlParser::_endsWith(const ::std::string &_text, const ::std::string &_ending)
{
  return _text.rfind(_ending) == (_text.size() - _ending.size());
}

::std::pair<::std::string, ::std::string> ls::std::io::XmlParser::_findAttribute(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name)
{
  ::std::pair<::std::string, ::std::string> attribute{};

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

size_t ls::std::io::XmlParser::_findAttributeEndPosition(const ls::std::core::type::byte_field &_data)
{
  ::std::string::size_type position = ::std::string::npos;
  ::std::string::size_type counter{};

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

ls::std::core::type::byte_field ls::std::io::XmlParser::_getNextTagString(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::core::type::byte_field tag{};
  size_t closingCharacterPosition = _index + _data.substr(_index).find('>');

  if (closingCharacterPosition != ::std::string::npos)
  {
    tag = _data.substr(_index, (closingCharacterPosition - _index) + 1);
  }

  return tag;
}

void ls::std::io::XmlParser::_isClosingTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 2) == "</")
  {
    this->mode = XML_PARSE_MODE_CLOSING_TAG;
  }
}

void ls::std::io::XmlParser::_isDeclaration(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  if (_data.substr(_index, 5) == "<?xml")
  {
    this->mode = XML_PARSE_MODE_DECLARATION;
  }
}

void ls::std::io::XmlParser::_isOpeningTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 1) == "<")
  {
    this->mode = XML_PARSE_MODE_OPENING_TAG;
  }
}

void ls::std::io::XmlParser::_isValue(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE)
  {
    ::std::string::size_type end = _data.substr(_index).find('<');
    bool isValue = _data[_index - 1] == '>' && end != ::std::string::npos && end > 0;

    if (isValue)
    {
      ::std::string value{_data.substr(_index, end)};

      if (!ls::std::io::XmlParser::_contains(value, "\n") && !ls::std::io::XmlParser::_contains(value, "\r\n"))
      {
        this->mode = XML_PARSE_MODE_VALUE;
      }
    }
  }
}

void ls::std::io::XmlParser::_mergeNodes()
{
  while (this->maxLevel > 1)
  {
    this->_mergeNodesOnCurrentLevel();
    this->maxLevel -= 1;
  }

  this->document->setRootElement(this->parseParameters.front().getNode());
}

void ls::std::io::XmlParser::_mergeChildrenToParentNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_parent, ::std::list<ls::std::io::XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel)
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

void ls::std::io::XmlParser::_mergeNodesOnCurrentLevel()
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

void ls::std::io::XmlParser::_parse(const ls::std::core::type::byte_field &_data)
{
  for (::std::string::size_type index = 0; index < _data.size(); index++)
  {
    switch (this->mode)
    {
      case XML_PARSE_MODE_ANALYZE:
      {
        this->_analyze(_data, index);
      }
      break;
      case XML_PARSE_MODE_DECLARATION:
      {
        --index;
        index = this->_parseDeclaration(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XML_PARSE_MODE_OPENING_TAG:
      {
        --index;
        index = ls::std::io::XmlParser::_parseOpeningTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XML_PARSE_MODE_VALUE:
      {
        --index;
        index = ls::std::io::XmlParser::_parseValue(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
      break;
      case XML_PARSE_MODE_CLOSING_TAG:
      {
        --index;
        index = ls::std::io::XmlParser::_parseClosingTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
      break;
    }
  }
}

::std::pair<::std::string, ::std::string> ls::std::io::XmlParser::_parseAttribute(const ls::std::core::type::byte_field &_data)
{
  ::std::pair<::std::string, ::std::string> parsedAttribute{};
  parsedAttribute.first = _data.substr(0, _data.find('='));
  parsedAttribute.second = _data.substr(_data.find('"') + 1);
  parsedAttribute.second.pop_back();

  return parsedAttribute;
}

::std::list<::std::pair<::std::string, ::std::string>> ls::std::io::XmlParser::_parseAttributes(ls::std::core::type::byte_field _data)
{
  ::std::list<::std::pair<::std::string, ::std::string>> attributes{};
  size_t position = _data.find(' ');
  _data = position == ::std::string::npos ? "" : _data.substr(position);

  while (!_data.empty())
  {
    do
    {
      position = _data.find(' ') + 1;
    } while (_data[position] == ' ');

    if (_data.size() <= 3 && ls::std::io::XmlParser::_endsWith(::std::string{_data}, ">"))
    {
      break;
    }

    ::std::string attributeString = _data.substr(position, ls::std::io::XmlParser::_findAttributeEndPosition(_data) + 1);
    attributes.push_back(ls::std::io::XmlParser::_parseAttribute(attributeString));
    _data = _data.substr(position + attributeString.size());
  }

  return attributes;
}

size_t ls::std::io::XmlParser::_parseClosingTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  ::std::string tagString = ls::std::io::XmlParser::_getNextTagString(_data, _index);
  this->currentLevel -= 1;
  return tagString.empty() ? _index : _index + (tagString.size() - 1);
}

size_t ls::std::io::XmlParser::_parseDeclaration(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  ::std::string tagString = ls::std::io::XmlParser::_getNextTagString(_data, _index);
  bool isValidTagString = !tagString.empty();

  if (isValidTagString)
  {
    ::std::shared_ptr<ls::std::io::XmlDeclaration> declaration = this->_createDeclaration(ls::std::io::XmlParser::_parseAttributes(tagString));
    this->document->setDeclaration(declaration);
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

size_t ls::std::io::XmlParser::_parseOpeningTag(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  ::std::string tagString{ls::std::io::XmlParser::_getNextTagString(_data, _index)};
  bool isValidTagString = !tagString.empty();
  ls::std::io::XmlParseParameter singleParseParameter{};

  if (isValidTagString)
  {
    ::std::shared_ptr<ls::std::io::XmlNode> node = ls::std::io::XmlParser::_createNode(ls::std::io::XmlParser::_parseAttributes(tagString), ls::std::io::XmlParser::_parseTagName(tagString));

    singleParseParameter.setLevel(this->currentLevel);
    singleParseParameter.setNode(node);
    this->parseParameters.push_back(singleParseParameter);

    if (!ls::std::io::XmlParser::_endsWith(tagString, "/>"))
    {
      this->currentLevel += 1;
      this->_setMaxLevel();
    }
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

ls::std::core::type::byte_field ls::std::io::XmlParser::_parseTagName(const ls::std::core::type::byte_field &_data)
{
  ::std::string::size_type position = _data.find(' ');

  if (position == ::std::string::npos)
  {
    position = _data.find('>');
  }

  return _data.substr(1, position - 1);
}

size_t ls::std::io::XmlParser::_parseValue(const ls::std::core::type::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::core::type::byte_field value = _data.substr(_index, _data.substr(_index).find('<'));
  this->parseParameters.back().getNode()->setValue(value);

  return _index + (value.size() - 1);
}

void ls::std::io::XmlParser::_reset()
{
  this->currentLevel = 1;
  this->maxLevel = 1;
  this->mode = XML_PARSE_MODE_ANALYZE;
  this->parseParameters.clear();
}

void ls::std::io::XmlParser::_setMaxLevel()
{
  if (this->currentLevel > this->maxLevel)
  {
    this->maxLevel = this->currentLevel;
  }
}
