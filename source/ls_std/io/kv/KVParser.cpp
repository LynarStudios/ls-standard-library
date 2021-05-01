/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/kv/KVParser.hpp>
#include <ls_std/exception/NullPointerException.hpp>
#include <ls_std/io/NewLine.hpp>

ls_std::KVParser::KVParser(const std::shared_ptr<ls_std::KVDocument> &_document) : ls_std::Class("KVParser")
{
  this->_assignDocument(_document);
}

std::shared_ptr<ls_std::KVDocument> ls_std::KVParser::getDocument()
{
  return this->document;
}

void ls_std::KVParser::parse(const ls_std::byte_field &_data)
{
  this->_parse(_data);
}

void ls_std::KVParser::setDocument(const std::shared_ptr<ls_std::KVDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::KVParser::_assignDocument(const std::shared_ptr<ls_std::KVDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls_std::NullPointerException{};
  }

  this->document = _document;
}

bool ls_std::KVParser::_lineHasPair(ls_std::KVParseData _parseData)
{
  return _parseData.line.contains("=") && _parseData.line.contains(";");
}

void ls_std::KVParser::_parse(const ls_std::byte_field &_data)
{
  for (std::string::size_type index = 0; index < _data.size(); index++)
  {
    ls_std::KVParseData parseData = ls_std::KVParser::_readLine(_data, index);
    this->_parsePair(parseData);
    index = parseData.index;
  }
}

void ls_std::KVParser::_parsePair(ls_std::KVParseData _parseData)
{
  if (ls_std::KVParser::_lineHasPair(_parseData))
  {
    size_t equalSignPosition = _parseData.line.toString().find('=');
    ls_std::kv_key key = _parseData.line.toString().substr(0, equalSignPosition);
    ls_std::kv_value value = _parseData.line.toString().substr(equalSignPosition + 1);
    value = value.substr(0, value.find(';'));

    this->document->addPair(ls_std::KVPair{key, value});
  }
}

ls_std::KVParseData ls_std::KVParser::_readLine(const ls_std::byte_field &_data, std::string::size_type _index)
{
  ls_std::KVParseData parseData{};
  parseData.line = _data.substr(_index);

  if (parseData.line.contains(ls_std::NewLine::getWindowsNewLine()))
  {
    ls_std::KVParser::_readLineWithWindowsLineBreak(parseData);
  }
  else
  {
    if (parseData.line.contains(ls_std::NewLine::getUnixNewLine()))
    {
      ls_std::KVParser::_readLineWithUnixLineBreak(parseData);
    }
  }

  parseData.index = _index + parseData.line.toString().size();
  return parseData;
}

void ls_std::KVParser::_readLineWithUnixLineBreak(ls_std::KVParseData &_parseData)
{
  size_t newLinePosition = _parseData.line.toString().find(ls_std::NewLine::getUnixNewLine());
  _parseData.line = _parseData.line.toString().substr(0, newLinePosition);
}

void ls_std::KVParser::_readLineWithWindowsLineBreak(ls_std::KVParseData &_parseData)
{
  size_t newLinePosition = _parseData.line.toString().find(ls_std::NewLine::getWindowsNewLine());
  _parseData.line = _parseData.line.toString().substr(0, newLinePosition + 1);
}
