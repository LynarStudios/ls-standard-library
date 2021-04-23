/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/kv/KVDocument.hpp>

ls_std::KVDocument::KVDocument() : ls_std::Class("KVDocument")
{}

bool ls_std::KVDocument::addPair(ls_std::KVPair _pair)
{
  bool added{};

  if (!this->_hasPair(_pair.getKey()))
  {
    std::pair<ls_std::kv_key, ls_std::KVPair> pair = std::make_pair(_pair.getKey(), _pair);
    added = this->pairs.insert(pair).second;
  }

  return added;
}

void ls_std::KVDocument::clear()
{
  this->pairs.clear();
}

std::map<ls_std::kv_key, ls_std::KVPair> ls_std::KVDocument::getPairs()
{
  return this->pairs;
}

bool ls_std::KVDocument::hasPair(const ls_std::kv_key &_key)
{
  return this->_hasPair(_key);
}

void ls_std::KVDocument::removePair(const ls_std::kv_key &_key)
{
  if (_hasPair(_key))
  {
    this->pairs.erase(_key);
  }
}

bool ls_std::KVDocument::_hasPair(const ls_std::kv_key &_key)
{
  return this->pairs.find(_key) != this->pairs.end();
}
