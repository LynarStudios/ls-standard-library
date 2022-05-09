/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/xml/XmlParser.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/boxing/String.hpp>

ls::XmlParser::XmlParser(const ::std::shared_ptr<ls::XmlDocument> &_document) : ls::std::core::Class("XmlParser")
{
  this->_assignDocument(_document);
  this->_reset();
}

::std::shared_ptr<ls::XmlDocument> ls::XmlParser::getDocument()
{
  return this->document;
}

void ls::XmlParser::parse(const ls::std::core::byte_field &_data)
{
  this->_parse(_data);
  this->_mergeNodes();
  this->_reset();
}

void ls::XmlParser::setDocument(const ::std::shared_ptr<ls::XmlDocument> &_document)
{
  this->_assignDocument(_document);
}

::std::pair<::std::string, ::std::string> ls::XmlParser::_readAttribute_(const ls::std::core::byte_field &_data)
{
  return ls::XmlParser::_parseAttribute(_data);
}

::std::list<::std::pair<::std::string, ::std::string>> ls::XmlParser::_readAttributes_(ls::std::core::byte_field _data)
{
  return ls::XmlParser::_parseAttributes(::std::move(_data));
}

void ls::XmlParser::_analyze(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  this->_isDeclaration(_data, _index);
  this->_isClosingTag(_data, _index);
  this->_isOpeningTag(_data, _index);
  this->_isValue(_data, _index);
}

void ls::XmlParser::_assignDocument(const ::std::shared_ptr<ls::XmlDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

::std::shared_ptr<ls::XmlDeclaration> ls::XmlParser::_createDeclaration(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes)
{
  ::std::shared_ptr<ls::XmlDeclaration> declaration = ::std::make_shared<ls::XmlDeclaration>("1.0");
  ::std::pair<::std::string, ::std::string> attribute = ls::XmlParser::_findAttribute(_attributes, "version");

  if (!attribute.first.empty())
  {
    declaration->setVersion(attribute.second);
  }

  attribute = ls::XmlParser::_findAttribute(_attributes, "encoding");

  if (!attribute.first.empty())
  {
    declaration->setEncoding(attribute.second);
  }

  attribute = ls::XmlParser::_findAttribute(_attributes, "standalone");

  if (!attribute.first.empty())
  {
    declaration->setStandalone(attribute.second);
  }

  return declaration;
}

::std::shared_ptr<ls::XmlNode> ls::XmlParser::_createNode(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name)
{
  ::std::shared_ptr<ls::XmlNode> node = ::std::make_shared<ls::XmlNode>(_name);
  ::std::shared_ptr<ls::XmlAttribute> attribute{};

  for (const auto &parsedAttribute : _attributes)
  {
    attribute = ::std::make_shared<ls::XmlAttribute>(parsedAttribute.first);
    attribute->setValue(parsedAttribute.second);
    node->addAttributeToEnd(attribute);
  }

  return node;
}

::std::pair<::std::string, ::std::string> ls::XmlParser::_findAttribute(const ::std::list<::std::pair<::std::string, ::std::string>> &_attributes, const ::std::string &_name)
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

size_t ls::XmlParser::_findAttributeEndPosition(const ls::std::core::byte_field &_data)
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

ls::std::core::byte_field ls::XmlParser::_getNextTagString(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::core::byte_field tag{};
  size_t closingCharacterPosition = _index + _data.substr(_index).find('>');

  if (closingCharacterPosition != ::std::string::npos)
  {
    tag = _data.substr(_index, (closingCharacterPosition - _index) + 1);
  }

  return tag;
}

void ls::XmlParser::_isClosingTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 2) == "</")
  {
    this->mode = XML_PARSE_MODE_CLOSING_TAG;
  }
}

void ls::XmlParser::_isDeclaration(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  if (_data.substr(_index, 5) == "<?xml")
  {
    this->mode = XML_PARSE_MODE_DECLARATION;
  }
}

void ls::XmlParser::_isOpeningTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 1) == "<")
  {
    this->mode = XML_PARSE_MODE_OPENING_TAG;
  }
}

void ls::XmlParser::_isValue(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  if (this->mode == XML_PARSE_MODE_ANALYZE)
  {
    ::std::string::size_type end = _data.substr(_index).find('<');
    bool isValue = _data[_index - 1] == '>' && end != ::std::string::npos && end > 0;

    if (isValue)
    {
      ls::std::boxing::String value{_data.substr(_index, end)};

      if (!value.contains("\n") && !value.contains("\r\n"))
      {
        this->mode = XML_PARSE_MODE_VALUE;
      }
    }
  }
}

void ls::XmlParser::_mergeNodes()
{
  while (this->maxLevel > 1)
  {
    this->_mergeNodesOnCurrentLevel();
    this->maxLevel -= 1;
  }

  this->document->setRootElement(this->parseParameters.front().node);
}

void ls::XmlParser::_mergeChildrenToParentNode(const ::std::shared_ptr<ls::XmlNode> &_parent, ::std::list<ls::XmlParseParameter>::iterator &_iterator, uint8_t _parentLevel)
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
      if (_iterator->level == this->maxLevel)
      {
        _parent->addChildToEnd(_iterator->node);
      }
    }
  } while (_iterator->level > _parentLevel);
}

void ls::XmlParser::_mergeNodesOnCurrentLevel()
{
  auto iterator = this->parseParameters.begin();
  uint8_t parentLevel = this->maxLevel - 1;

  while (iterator != this->parseParameters.end())
  {
    if (iterator->level == parentLevel)
    {
      this->_mergeChildrenToParentNode(iterator->node, iterator, parentLevel);
    }
    else
    {
      iterator++;
    }
  }
}

void ls::XmlParser::_parse(const ls::std::core::byte_field &_data)
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
        index = ls::XmlParser::_parseOpeningTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
        break;
      case XML_PARSE_MODE_VALUE:
      {
        --index;
        index = ls::XmlParser::_parseValue(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
        break;
      case XML_PARSE_MODE_CLOSING_TAG:
      {
        --index;
        index = ls::XmlParser::_parseClosingTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      }
        break;
    }
  }
}

::std::pair<::std::string, ::std::string> ls::XmlParser::_parseAttribute(const ls::std::core::byte_field &_data)
{
  ::std::pair<::std::string, ::std::string> parsedAttribute{};
  parsedAttribute.first = _data.substr(0, _data.find('='));
  parsedAttribute.second = _data.substr(_data.find('"') + 1);
  parsedAttribute.second.pop_back();

  return parsedAttribute;
}

::std::list<::std::pair<::std::string, ::std::string>> ls::XmlParser::_parseAttributes(ls::std::core::byte_field _data)
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

    if (_data.size() <= 3 && ls::std::boxing::String{_data}.endsWith(">"))
    {
      break;
    }

    ::std::string attributeString = _data.substr(position, ls::XmlParser::_findAttributeEndPosition(_data) + 1);
    attributes.push_back(ls::XmlParser::_parseAttribute(attributeString));
    _data = _data.substr(position + attributeString.size());
  }

  return attributes;
}

size_t ls::XmlParser::_parseClosingTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ::std::string tagString = ls::XmlParser::_getNextTagString(_data, _index);
  this->currentLevel -= 1;
  return tagString.empty() ? _index : _index + (tagString.size() - 1);
}

size_t ls::XmlParser::_parseDeclaration(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ::std::string tagString = ls::XmlParser::_getNextTagString(_data, _index);
  bool isValidTagString = !tagString.empty();

  if (isValidTagString)
  {
    ::std::shared_ptr<ls::XmlDeclaration> declaration = this->_createDeclaration(ls::XmlParser::_parseAttributes(tagString));
    this->document->setDeclaration(declaration);
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

size_t ls::XmlParser::_parseOpeningTag(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::boxing::String tagString{ls::XmlParser::_getNextTagString(_data, _index)};
  bool isValidTagString = !tagString.toString().empty();
  ls::XmlParseParameter singleParseParameter{};

  if (isValidTagString)
  {
    ::std::shared_ptr<ls::XmlNode> node = ls::XmlParser::_createNode(ls::XmlParser::_parseAttributes(tagString), ls::XmlParser::_parseTagName(tagString));

    singleParseParameter.level = this->currentLevel;
    singleParseParameter.node = node;
    this->parseParameters.push_back(singleParseParameter);

    if (!tagString.endsWith("/>"))
    {
      this->currentLevel += 1;
      this->_setMaxLevel();
    }
  }

  return !isValidTagString ? _index : _index + (tagString.toString().size() - 1);
}

ls::std::core::byte_field ls::XmlParser::_parseTagName(const ls::std::core::byte_field &_data)
{
  ::std::string::size_type position = _data.find(' ');

  if (position == ::std::string::npos)
  {
    position = _data.find('>');
  }

  return _data.substr(1, position - 1);
}

size_t ls::XmlParser::_parseValue(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::core::byte_field value = _data.substr(_index, _data.substr(_index).find('<'));
  this->parseParameters.back().node->setValue(value);

  return _index + (value.size() - 1);
}

void ls::XmlParser::_reset()
{
  this->currentLevel = 1;
  this->maxLevel = 1;
  this->mode = XML_PARSE_MODE_ANALYZE;
  this->parseParameters.clear();
}

void ls::XmlParser::_setMaxLevel()
{
  if (this->currentLevel > this->maxLevel)
  {
    this->maxLevel = this->currentLevel;
  }
}
