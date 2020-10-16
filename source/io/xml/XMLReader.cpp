/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-10-16
 *
 * */

#include "XMLReader.hpp"
#include "../../exception/IllegalArgumentException.hpp"
#include "../FileReader.hpp"
#include "../../boxing/String.hpp"
#include <vector>

ls_std::XMLReader::XMLReader(const std::shared_ptr<ls_std::XMLDocument>& _document, const std::string& _absolutePath) :
Class("XMLReader"),
xmlFile(ls_std::File {_absolutePath}),
document(_document)
{
  XMLReader::_checkDocumentExistence(_document);
  XMLReader::_checkFileExistence(this->xmlFile);
}

ls_std::byte_field ls_std::XMLReader::read()
{
  ls_std::byte_field data = ls_std::FileReader {this->xmlFile}.read();
  this->_read(data);

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

void ls_std::XMLReader::_read(const ls_std::byte_field &_data)
{
  for(std::string::size_type index = 0 ; index < _data.size() ; index++) {
    switch(this->mode) {
      case XML_PARSE_MODE_ANALYZE:
      {
        this->_isDeclaration(_data, index);
        this->_isClosingTag(_data, index);
        this->_isOpeningTag(_data, index);
      } break;
      case XML_PARSE_MODE_DECLARATION:
      {
        --index;
        index = ls_std::XMLReader::_readDeclaration(_data, index);
        this->mode = XML_PARSE_MODE_ANALYZE;
      } break;
      case XML_PARSE_MODE_OPENING_TAG:
      {

      } break;
      case XML_PARSE_MODE_CLOSING_TAG:
      {

      } break;
    }
  }
}

std::pair<std::string, std::string> ls_std::XMLReader::_readAttribute(const ls_std::byte_field &_data)
{
  std::pair<std::string, std::string> parsedAttribute {};
  parsedAttribute.first = _data.substr(0, _data.find('='));
  parsedAttribute.second  = _data.substr(_data.find('"') + 1);
  parsedAttribute.second.pop_back();

  return parsedAttribute;
}

std::list<std::pair<std::string, std::string>> ls_std::XMLReader::_readAttributes(ls_std::byte_field _data)
{
  std::list<std::pair<std::string, std::string>> attributes {};
  size_t attributePosition;
  _data = _data.substr(5);

  while(!_data.empty()) {
    do {
      attributePosition = _data.find(' ') + 1;
    }
    while(_data[attributePosition] == ' ');

    if(_data.size() <= 3 && ls_std::String {_data}.endsWith(">")) {
      break;
    }

    std::string attributeString = _data.substr(attributePosition, _data.find(R"(" )"));
    attributes.push_back(ls_std::XMLReader::_readAttribute(attributeString));
    _data = _data.substr(attributePosition + attributeString.size());
  }

  return attributes;
}

size_t ls_std::XMLReader::_readDeclaration(const ls_std::byte_field &_data, std::string::size_type _index)
{
  size_t closingTagPosition = _data.find('>');

  if(closingTagPosition != std::string::npos) {
    std::string declarationString = _data.substr(_index, (closingTagPosition - _index) + 1);
    std::shared_ptr<ls_std::XMLDeclaration> declaration = this->_createDeclaration(ls_std::XMLReader::_readAttributes(declarationString));
    this->document->setDeclaration(declaration);
  }

  return (closingTagPosition == std::string::npos) ? _index : closingTagPosition;
}

