/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-07-15
 *
 * */

#include <ls_std/io/kv/KvParser.hpp>
#include <ls_std/io/NewLine.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::KvParser::KvParser(const std::shared_ptr<ls_std::KvDocument> &_document) : ls_std::Class("KvParser")
{
  this->_assignDocument(_document);
}

std::shared_ptr<ls_std::KvDocument> ls_std::KvParser::getDocument()
{
  return this->document;
}

void ls_std::KvParser::parse(const ls_std::byte_field &_data)
{
  this->_parse(_data);
}

void ls_std::KvParser::setDocument(const std::shared_ptr<ls_std::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls_std::KvParser::_assignDocument(const std::shared_ptr<ls_std::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->document = _document;
}

bool ls_std::KvParser::_lineHasPair(ls_std::KvParseParameter _parseParameter)
{
  return _parseParameter.line.contains("=") && _parseParameter.line.contains(";");
}

void ls_std::KvParser::_parse(const ls_std::byte_field &_data)
{
  for (std::string::size_type index = 0; index < _data.size(); index++)
  {
    ls_std::KvParseParameter parseParameter = ls_std::KvParser::_readLine(_data, index);
    this->_parsePair(parseParameter);
    index = parseParameter.index;
  }
}

void ls_std::KvParser::_parsePair(ls_std::KvParseParameter _parseParameter)
{
  if (ls_std::KvParser::_lineHasPair(_parseParameter))
  {
    size_t equalSignPosition = _parseParameter.line.toString().find('=');
    ls_std::kv_key key = _parseParameter.line.toString().substr(0, equalSignPosition);
    ls_std::kv_value value = _parseParameter.line.toString().substr(equalSignPosition + 1);
    value = value.substr(0, value.find(';'));

    this->document->addPair(ls_std::KvPair{key, value});
  }
}

ls_std::KvParseParameter ls_std::KvParser::_readLine(const ls_std::byte_field &_data, std::string::size_type _index)
{
  ls_std::KvParseParameter parseParameter{};
  parseParameter.line = _data.substr(_index);

  if (parseParameter.line.contains(ls_std::NewLine::getWindowsNewLine()))
  {
    ls_std::KvParser::_readLineWithWindowsLineBreak(parseParameter);
  }
  else
  {
    if (parseParameter.line.contains(ls_std::NewLine::getUnixNewLine()))
    {
      ls_std::KvParser::_readLineWithUnixLineBreak(parseParameter);
    }
  }

  parseParameter.index = _index + parseParameter.line.toString().size();
  return parseParameter;
}

void ls_std::KvParser::_readLineWithUnixLineBreak(ls_std::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls_std::NewLine::getUnixNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition);
}

void ls_std::KvParser::_readLineWithWindowsLineBreak(ls_std::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls_std::NewLine::getWindowsNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition + 1);
}
