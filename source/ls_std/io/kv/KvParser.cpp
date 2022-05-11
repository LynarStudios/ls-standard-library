/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/io/kv/KvParser.hpp>
#include <ls_std/io/NewLine.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::io::KvParser::KvParser(const ::std::shared_ptr<ls::std::io::KvDocument> &_document) : ls::std::core::Class("KvParser")
{
  this->_assignDocument(_document);
}

std::shared_ptr<ls::std::io::KvDocument> ls::std::io::KvParser::getDocument()
{
  return this->document;
}

void ls::std::io::KvParser::parse(const ls::std::core::byte_field &_data)
{
  this->_parse(_data);
}

void ls::std::io::KvParser::setDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document)
{
  this->_assignDocument(_document);
}

void ls::std::io::KvParser::_assignDocument(const ::std::shared_ptr<ls::std::io::KvDocument> &_document)
{
  if (_document == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->document = _document;
}

bool ls::std::io::KvParser::_lineHasPair(ls::std::io::KvParseParameter _parseParameter)
{
  return _parseParameter.line.contains("=") && _parseParameter.line.contains(";");
}

void ls::std::io::KvParser::_parse(const ls::std::core::byte_field &_data)
{
  for (::std::string::size_type index = 0; index < _data.size(); index++)
  {
    ls::std::io::KvParseParameter parseParameter = ls::std::io::KvParser::_readLine(_data, index);
    this->_parsePair(parseParameter);
    index = parseParameter.index;
  }
}

void ls::std::io::KvParser::_parsePair(ls::std::io::KvParseParameter _parseParameter)
{
  if (ls::std::io::KvParser::_lineHasPair(_parseParameter))
  {
    size_t equalSignPosition = _parseParameter.line.toString().find('=');
    ls::std::io::kv_key key = _parseParameter.line.toString().substr(0, equalSignPosition);
    ls::std::io::kv_value value = _parseParameter.line.toString().substr(equalSignPosition + 1);
    value = value.substr(0, value.find(';'));

    this->document->addPair(ls::std::io::KvPair{key, value});
  }
}

ls::std::io::KvParseParameter ls::std::io::KvParser::_readLine(const ls::std::core::byte_field &_data, ::std::string::size_type _index)
{
  ls::std::io::KvParseParameter parseParameter{};
  parseParameter.line = _data.substr(_index);

  if (parseParameter.line.contains(ls::std::io::NewLine::getWindowsNewLine()))
  {
    ls::std::io::KvParser::_readLineWithWindowsLineBreak(parseParameter);
  }
  else
  {
    if (parseParameter.line.contains(ls::std::io::NewLine::getUnixNewLine()))
    {
      ls::std::io::KvParser::_readLineWithUnixLineBreak(parseParameter);
    }
  }

  parseParameter.index = _index + parseParameter.line.toString().size();
  return parseParameter;
}

void ls::std::io::KvParser::_readLineWithUnixLineBreak(ls::std::io::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls::std::io::NewLine::getUnixNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition);
}

void ls::std::io::KvParser::_readLineWithWindowsLineBreak(ls::std::io::KvParseParameter &_parseParameter)
{
  size_t newLinePosition = _parseParameter.line.toString().find(ls::std::io::NewLine::getWindowsNewLine());
  _parseParameter.line = _parseParameter.line.toString().substr(0, newLinePosition + 1);
}
