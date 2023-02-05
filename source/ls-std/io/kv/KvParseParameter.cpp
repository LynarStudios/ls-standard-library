/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <ls-std/io/kv/KvParseParameter.hpp>

ls::std::io::KvParseParameter::KvParseParameter() = default;

ls::std::io::KvParseParameter::~KvParseParameter() = default;

::std::string::size_type ls::std::io::KvParseParameter::getIndex() const
{
  return this->index;
}

::std::string ls::std::io::KvParseParameter::getLine()
{
  return this->line;
}

void ls::std::io::KvParseParameter::setIndex(const ::std::string::size_type &_index)
{
  this->index = _index;
}

void ls::std::io::KvParseParameter::setLine(const ::std::string &_line)
{
  this->line = _line;
}
