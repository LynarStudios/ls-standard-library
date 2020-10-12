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

void ls_std::XMLReader::_read(const ls_std::byte_field &_data)
{
  uint8_t mode {};

  for(std::string::size_type i = 0 ; i < _data.size() ; i++) {
    switch(mode)
    {
      case 1: // xml declaration
      {

      } break;
      case 2: // xml opening tag
      {

      } break;
      case 3: // xml closing tag
      {

      } break;
      case 4: // xml attribute
      {

      } break;
    }
  }
}
