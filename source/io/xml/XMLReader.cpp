/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-10
 * Changed:         2020-10-10
 *
 * */

#include "XMLReader.hpp"
#include "../../exception/IllegalArgumentException.hpp"
#include "../FileReader.hpp"

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

std::shared_ptr<ls_std::XMLDeclaration> ls_std::XMLReader::_createDeclaration(const std::unordered_map<std::string, std::string>& _attributes)
{
  std::shared_ptr<ls_std::XMLDeclaration> declaration = std::make_shared<ls_std::XMLDeclaration>("1.0");

  if(_attributes.find("version") != _attributes.end()) {
    declaration->setVersion(_attributes.at("version"));
  }

  if(_attributes.find("encoding") != _attributes.end()) {
    declaration->setEncoding(_attributes.at("encoding"));
  }

  if(_attributes.find("standalone") != _attributes.end()) {
    declaration->setStandalone(_attributes.at("standalone"));
  }

  return declaration;
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
      }
      case XML_PARSE_MODE_DECLARATION:
      {
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

std::unordered_map<std::string, std::string> ls_std::XMLReader::_readAttributes(ls_std::byte_field _data)
{
  std::unordered_map<std::string, std::string> attributes {};
  size_t attributePosition;
  _data = _data.substr(5);

  while(!_data.empty()) {
    do {
      attributePosition = _data.find(' ') + 1;
    }
    while(_data[attributePosition] == ' ');

    std::string attributeString = _data.substr(attributePosition, _data.find(R"(" )"));
    attributes.insert(ls_std::XMLReader::_readAttribute(attributeString));
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

