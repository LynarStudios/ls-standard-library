/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-11-06
 *
 * */

#include "XMLReader.hpp"
#include "../../exception/IllegalArgumentException.hpp"
#include "../FileReader.hpp"
#include "../../../../include/ls_std/boxing/String.hpp"

ls_std::XMLReader::XMLReader(const std::shared_ptr<ls_std::XMLDocument>& _document, const std::string& _absolutePath) :
Class("XMLReader"),
xmlFile(ls_std::File {_absolutePath}),
document(_document)
{
  XMLReader::_checkDocumentExistence(_document);
  XMLReader::_checkFileExistence(this->xmlFile);
  this->_reset();
}

ls_std::byte_field ls_std::XMLReader::read()
{
  ls_std::byte_field data = ls_std::FileReader {this->xmlFile}.read();
  this->_parse(data);
  this->_mergeNodes();
  this->_reset();

  return data;
}

std::shared_ptr<ls_std::XMLDocument> ls_std::XMLReader::getDocument()
{
  return this->document;
}

void ls_std::XMLReader::setFile(const ls_std::File &_xmlFile)
{
  XMLReader::_checkFileExistence(_xmlFile);
  this->xmlFile = _xmlFile;
}

std::pair<std::string, std::string> ls_std::XMLReader::_readAttribute_(const ls_std::byte_field &_data)
{
  return ls_std::XMLReader::_parseAttribute(_data);
}

std::list<std::pair<std::string, std::string>> ls_std::XMLReader::_readAttributes_(ls_std::byte_field _data)
{
  return ls_std::XMLReader::_parseAttributes(std::move(_data));
}

void ls_std::XMLReader::_analyze(const ls_std::byte_field &_data, std::string::size_type _index)
{
  this->_isDeclaration(_data, _index);
  this->_isClosingTag(_data, _index);
  this->_isOpeningTag(_data, _index);
  this->_isValue(_data, _index);
}

void ls_std::XMLReader::_checkDocumentExistence(const std::shared_ptr<ls_std::XMLDocument>& _document)
{
  if(_document == nullptr) {
    throw ls_std::IllegalArgumentException {};
  }
}

void ls_std::XMLReader::_checkFileExistence(ls_std::File _xmlFile)
{
  if(!_xmlFile.exists()) {
    throw ls_std::IllegalArgumentException {};
  }
}

std::shared_ptr<ls_std::XMLDeclaration> ls_std::XMLReader::_createDeclaration(const std::list<std::pair<std::string, std::string>>& _attributes)
{
  std::shared_ptr<ls_std::XMLDeclaration> declaration = std::make_shared<ls_std::XMLDeclaration>("1.0");
  std::pair<std::string, std::string> attribute = ls_std::XMLReader::_findAttribute(_attributes, "version");

  if(!attribute.first.empty()) {
    declaration->setVersion(attribute.second);
  }

  attribute = ls_std::XMLReader::_findAttribute(_attributes, "encoding");

  if(!attribute.first.empty()) {
    declaration->setEncoding(attribute.second);
  }

  attribute = ls_std::XMLReader::_findAttribute(_attributes, "standalone");

  if(!attribute.first.empty()) {
    declaration->setStandalone(attribute.second);
  }

  return declaration;
}

std::shared_ptr<ls_std::XMLNode> ls_std::XMLReader::_createNode(const std::list<std::pair<std::string, std::string>> &_attributes, const std::string& _name)
{
  std::shared_ptr<ls_std::XMLNode> node = std::make_shared<ls_std::XMLNode>(_name);
  std::shared_ptr<ls_std::XMLAttribute> attribute {};

  for(const auto& parsedAttribute : _attributes) {
    attribute = std::make_shared<ls_std::XMLAttribute>(parsedAttribute.first);
    attribute->setValue(parsedAttribute.second);
    node->addAttributeToEnd(attribute);
  }

  return node;
}

std::pair<std::string, std::string> ls_std::XMLReader::_findAttribute(const std::list<std::pair<std::string, std::string>> &_attributes, const std::string &_name)
{
  std::pair<std::string, std::string> attribute {};

  for(const auto& currentAttribute : _attributes) {
    if(currentAttribute.first == _name) {
      attribute = currentAttribute;
      break;
    }
  }

  return attribute;
}

size_t ls_std::XMLReader::_findAttributeEndPosition(const ls_std::byte_field &_data)
{
  std::string::size_type position = std::string::npos;
  std::string::size_type counter {};

  for(char letter : _data) {
    if(letter == '"') {
      counter++;
    }

    if(counter == 2) {
      break;
    }

    position++;
  }

  return position;
}

ls_std::byte_field ls_std::XMLReader::_getNextTagString(const ls_std::byte_field &_data, std::string::size_type _index)
{
  ls_std::byte_field tag {};
  size_t closingCharacterPosition = _index + _data.substr(_index).find('>');

  if(closingCharacterPosition != std::string::npos) {
    tag = _data.substr(_index, (closingCharacterPosition - _index) + 1);
  }

  return tag;
}

void ls_std::XMLReader::_isClosingTag(const ls_std::byte_field &_data, std::string::size_type _index)
{
  if(this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 2) == "</") {
    this->mode = XML_PARSE_MODE_CLOSING_TAG;
  }
}

void ls_std::XMLReader::_isDeclaration(const ls_std::byte_field& _data, std::string::size_type _index)
{
  if(_data.substr(_index, 5) == "<?xml") {
    this->mode = XML_PARSE_MODE_DECLARATION;
  }
}

void ls_std::XMLReader::_isOpeningTag(const ls_std::byte_field &_data, std::string::size_type _index)
{
  if(this->mode == XML_PARSE_MODE_ANALYZE && _data.substr(_index, 1) == "<") {
    this->mode = XML_PARSE_MODE_OPENING_TAG;
  }
}

void ls_std::XMLReader::_isValue(const ls_std::byte_field &_data, std::string::size_type _index)
{
  if(this->mode == XML_PARSE_MODE_ANALYZE) {
    std::string::size_type end = _data.substr(_index).find('<');
    bool isValue = _data[_index - 1] == '>' && end != std::string::npos && end > 0;

    if(isValue) {
      ls_std::String value {_data.substr(_index, end)};

      if(!value.contains("\n") && !value.contains("\r\n") ) {
        this->mode = XML_PARSE_MODE_VALUE;
      }
    }
  }
}

void ls_std::XMLReader::_mergeNodes()
{
  while(this->maxLevel > 1) {
    this->_mergeNodesOnCurrentLevel();
    this->maxLevel -= 1;
  }

  this->document->setRootElement(this->parseData.front().node);
}

void ls_std::XMLReader::_mergeChildrenToParentNode(const std::shared_ptr<ls_std::XMLNode>& _parent, std::list<ls_std::XMLParseData>::iterator& _iterator, uint8_t _parentLevel)
{
  do {
    _iterator++;

    if(_iterator == this->parseData.end()) {
      break;
    }
    else {
      if(_iterator->level == this->maxLevel) {
        _parent->addChildToEnd(_iterator->node);
      }
    }
  }
  while(_iterator->level > _parentLevel);
}

void ls_std::XMLReader::_mergeNodesOnCurrentLevel() {
  auto iterator = this->parseData.begin();
  uint8_t parentLevel = this->maxLevel - 1;

  while(iterator != this->parseData.end()) {
    if(iterator->level == parentLevel) {
      this->_mergeChildrenToParentNode(iterator->node, iterator, parentLevel);
    }
    else {
      iterator++;
    }
  }
}

void ls_std::XMLReader::_parse(const ls_std::byte_field &_data)
{
  for(std::string::size_type index = 0 ; index < _data.size() ; index++) {
    switch(this->mode) {
      case XML_PARSE_MODE_ANALYZE:
      {
        this->_analyze(_data, index);
      } break;
      case XML_PARSE_MODE_DECLARATION:
      {
        --index;
        index = this->_parseDeclaration(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      } break;
      case XML_PARSE_MODE_OPENING_TAG:
      {
        --index;
        index = ls_std::XMLReader::_parseOpeningTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      } break;
      case XML_PARSE_MODE_VALUE:
      {
        --index;
        index = ls_std::XMLReader::_parseValue(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      } break;
      case XML_PARSE_MODE_CLOSING_TAG:
      {
        --index;
        index = ls_std::XMLReader::_parseClosingTag(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      } break;
    }
  }
}

std::pair<std::string, std::string> ls_std::XMLReader::_parseAttribute(const ls_std::byte_field &_data)
{
  std::pair<std::string, std::string> parsedAttribute {};
  parsedAttribute.first = _data.substr(0, _data.find('='));
  parsedAttribute.second  = _data.substr(_data.find('"') + 1);
  parsedAttribute.second.pop_back();

  return parsedAttribute;
}

std::list<std::pair<std::string, std::string>> ls_std::XMLReader::_parseAttributes(ls_std::byte_field _data)
{
  std::list<std::pair<std::string, std::string>> attributes {};
  size_t position = _data.find(' ');
  _data = position == std::string::npos ? "" : _data.substr(position);

  while(!_data.empty()) {
    do {
      position = _data.find(' ') + 1;
    }
    while(_data[position] == ' ');

    if(_data.size() <= 3 && ls_std::String {_data}.endsWith(">")) {
      break;
    }

    std::string attributeString = _data.substr(position, ls_std::XMLReader::_findAttributeEndPosition(_data) + 1);
    attributes.push_back(ls_std::XMLReader::_parseAttribute(attributeString));
    _data = _data.substr(position + attributeString.size());
  }

  return attributes;
}

size_t ls_std::XMLReader::_parseClosingTag(const ls_std::byte_field &_data, std::string::size_type _index)
{
  std::string tagString = ls_std::XMLReader::_getNextTagString(_data, _index);
  this->currentLevel -= 1;
  return tagString.empty() ? _index : _index + (tagString.size() - 1);
}

size_t ls_std::XMLReader::_parseDeclaration(const ls_std::byte_field &_data, std::string::size_type _index)
{
  std::string tagString = ls_std::XMLReader::_getNextTagString(_data, _index);
  bool isValidTagString = !tagString.empty();

  if(isValidTagString) {
    std::shared_ptr<ls_std::XMLDeclaration> declaration = this->_createDeclaration(ls_std::XMLReader::_parseAttributes(tagString));
    this->document->setDeclaration(declaration);
  }

  return !isValidTagString ? _index : _index + (tagString.size() - 1);
}

size_t ls_std::XMLReader::_parseOpeningTag(const ls_std::byte_field &_data, std::string::size_type _index)
{
  ls_std::String tagString {ls_std::XMLReader::_getNextTagString(_data, _index)};
  bool isValidTagString = !tagString.toString().empty();
  ls_std::XMLParseData singleParseData {};

  if(isValidTagString) {
    std::shared_ptr<ls_std::XMLNode> node = ls_std::XMLReader::_createNode(ls_std::XMLReader::_parseAttributes(tagString), ls_std::XMLReader::_parseTagName(tagString));

    singleParseData.level = this->currentLevel;
    singleParseData.node = node;
    this->parseData.push_back(singleParseData);

    if(!tagString.endsWith("/>")) {
      this->currentLevel += 1;
      this->_setMaxLevel();
    }
  }

  return !isValidTagString ? _index : _index + (tagString.toString().size() - 1);
}

ls_std::byte_field ls_std::XMLReader::_parseTagName(const ls_std::byte_field &_data)
{
  std::string::size_type position = _data.find(' ');

  if(position == std::string::npos) {
    position = _data.find('>');
  }

  return _data.substr(1, position - 1);
}

size_t ls_std::XMLReader::_parseValue(const ls_std::byte_field &_data, std::string::size_type _index)
{
  ls_std::byte_field value = _data.substr(_index, _data.substr(_index).find('<'));
  this->parseData.back().node->setValue(value);

  return _index + (value.size() - 1);
}

void ls_std::XMLReader::_reset()
{
  this->currentLevel = 1;
  this->maxLevel = 1;
  this->mode = XML_PARSE_MODE_ANALYZE;
  this->parseData.clear();
}

void ls_std::XMLReader::_setMaxLevel()
{
  if(this->currentLevel > this->maxLevel) {
    this->maxLevel = this->currentLevel;
  }
}
