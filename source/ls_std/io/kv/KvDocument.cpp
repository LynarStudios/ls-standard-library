/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/io/kv/KvDocument.hpp>

ls::std::io::KvDocument::KvDocument() : ls::std::core::Class("KvDocument")
{}

bool ls::std::io::KvDocument::addPair(ls::std::io::KvPair _pair)
{
  bool added{};

  if (!this->_hasPair(_pair.getKey()))
  {
    ::std::pair<ls::std::core::type::kv_key, ls::std::io::KvPair> pair = ::std::make_pair(_pair.getKey(), _pair);
    added = this->pairs.insert(pair).second;
  }

  return added;
}

void ls::std::io::KvDocument::clear()
{
  this->pairs.clear();
}

std::map<ls::std::core::type::kv_key, ls::std::io::KvPair> ls::std::io::KvDocument::getPairs()
{
  return this->pairs;
}

bool ls::std::io::KvDocument::hasPair(const ls::std::core::type::kv_key &_key)
{
  return this->_hasPair(_key);
}

bool ls::std::io::KvDocument::removePair(const ls::std::core::type::kv_key &_key)
{
  return this->pairs.erase(_key) == 1;
}

bool ls::std::io::KvDocument::_hasPair(const ls::std::core::type::kv_key &_key)
{
  return this->pairs.find(_key) != this->pairs.end();
}
