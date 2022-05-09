/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/kv/KvDocument.hpp>

ls::KvDocument::KvDocument() : ls::std::core::Class("KvDocument")
{}

bool ls::KvDocument::addPair(ls::KvPair _pair)
{
  bool added{};

  if (!this->_hasPair(_pair.getKey()))
  {
    ::std::pair<ls::kv_key, ls::KvPair> pair = ::std::make_pair(_pair.getKey(), _pair);
    added = this->pairs.insert(pair).second;
  }

  return added;
}

void ls::KvDocument::clear()
{
  this->pairs.clear();
}

std::map<ls::kv_key, ls::KvPair> ls::KvDocument::getPairs()
{
  return this->pairs;
}

bool ls::KvDocument::hasPair(const ls::kv_key &_key)
{
  return this->_hasPair(_key);
}

bool ls::KvDocument::removePair(const ls::kv_key &_key)
{
  return this->pairs.erase(_key) == 1;
}

bool ls::KvDocument::_hasPair(const ls::kv_key &_key)
{
  return this->pairs.find(_key) != this->pairs.end();
}
