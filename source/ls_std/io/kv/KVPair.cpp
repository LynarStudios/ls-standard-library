/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/kv/KVPair.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::KVPair::KVPair(const ls_std::kv_key &_key, ls_std::kv_value _value)
    : ls_std::Class("KVPair"),
      value(std::move(_value))
{
  this->_assignKey(_key);
}

ls_std::kv_key ls_std::KVPair::getKey()
{
  return this->key;
}

ls_std::kv_value ls_std::KVPair::getValue()
{
  return this->value;
}

void ls_std::KVPair::setValue(const ls_std::kv_value &_value)
{
  this->value = _value;
}

void ls_std::KVPair::_assignKey(const ls_std::kv_key &_key)
{
  if (_key.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->key = _key;
}
