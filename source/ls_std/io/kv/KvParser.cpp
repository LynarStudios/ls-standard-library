/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/kv/KvParser.hpp>
#include <ls_std/io/NewLine.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::KvParser::KvParser(const ::std::shared_ptr<ls::KvDocument> &_document) : ls::std::core::Class("KvParser")
{
  this->_assignDocument(_document);
}

std::shared_ptr<ls::KvDocument> ls::KvParser::getDocument()
{
  return this->document;
}

void ls::KvParser::parse(const ls::std::core::byte_field &_data)
{
  this->_parse(_data);
}

void ls::KvParser::setDocument(const ::std::shared_ptr<ls::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::KvParser::_assignDocument(const ::std::shared_ptr<ls::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

bool ls::KvParser::_lineHasPair(ls::KvParseParameter _parseParameter)
{
  return _parseParameter.line.contains("=") && _parseParameter.line.contains(";");
}

void ls::KvParser::_parse(const ls::std::core::byte_field &_data)
{
  for (::std::string::size_type index = 0; index < _data.size(); index++)
  {
    ls::KvParseParameter parseParameter = ls::KvParser::_readLine(_data, index);
    this->_parsePair(parseParameter);
    index = parseParameter.index;
  }
}

void ls::KvParser::_parsePair(ls::KvParseParameter _parseParameter)
{
  if (ls::KvParser::_lineHasPair(_parseParameter))
  {
    size_t equalSignPosition = _parseParameter.line.toString().find('=');
    ls::kv_key key = _parseParameter.line.toString().substr(0, equalSignPosition);
    ls::kv_value value = _parseParameter.line.toString().substr(equalSignPosition + 1);
    value = value.substr(0, value.find(';'));

    this->document->addPair(ls::KvPair{key, value});
  }
}

ls::KvParseParameter ls::KvParser::_readLine(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ls::KvParseParameter parseParameter{};
  parseParameter.line = _data.substr(_index);

  if (parseParameter.line.contains(ls::NewLine::getWindowsNewLine()))
  {
    ls::KvParser::_readLineWithWindowsLineBreak(parseParameter);
  }
  else
  {
    if (parseParameter.line.contains(ls::NewLine::getUnixNewLine()))
    {
      ls::KvParser::_readLineWithUnixLineBreak(parseParameter);
    }
  }

  parseParameter.index = _index + parseParameter.line.toString().size();
  return parseParameter;
}

void ls::KvParser::_readLineWithUnixLineBreak(ls::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls::NewLine::getUnixNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition);
}

void ls::KvParser::_readLineWithWindowsLineBreak(ls::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls::NewLine::getWindowsNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition + 1);
}
