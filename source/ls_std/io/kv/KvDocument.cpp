/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-07-15
 *
 * */

#include <ls_std/io/kv/KvDocument.hpp>

ls_std::KvDocument::KvDocument() : ls_std::Class("KvDocument")
{}

bool ls_std::KvDocument::addPair(ls_std::KvPair _pair)
{
  bool added{};

  if (!this->_hasPair(_pair.getKey()))
  {
    std::pair<ls_std::kv_key, ls_std::KvPair> pair = std::make_pair(_pair.getKey(), _pair);
    added = this->pairs.insert(pair).second;
  }

  return added;
}

void ls_std::KvDocument::clear()
{
  this->pairs.clear();
}

std::map<ls_std::kv_key, ls_std::KvPair> ls_std::KvDocument::getPairs()
{
  return this->pairs;
}

bool ls_std::KvDocument::hasPair(const ls_std::kv_key &_key)
{
  return this->_hasPair(_key);
}

bool ls_std::KvDocument::removePair(const ls_std::kv_key &_key)
{
  return this->pairs.erase(_key) == 1;
}

bool ls_std::KvDocument::_hasPair(const ls_std::kv_key &_key)
{
  return this->pairs.find(_key) != this->pairs.end();
}
