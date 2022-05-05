/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/kv/KvPair.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::KvPair::KvPair(const ls::kv_key &_key, ls::kv_value _value)
    : ls::Class("KvPair"),
      value(std::move(_value))
{
  this->_assignKey(_key);
}

ls::kv_key ls::KvPair::getKey()
{
  return this->key;
}

ls::kv_value ls::KvPair::getValue()
{
  return this->value;
}

void ls::KvPair::setValue(const ls::kv_value &_value)
{
  this->value = _value;
}

void ls::KvPair::_assignKey(const ls::kv_key &_key)
{
  if (_key.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->key = _key;
}
