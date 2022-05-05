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

ls_std::KvPair::KvPair(const ls_std::kv_key &_key, ls_std::kv_value _value)
    : ls_std::Class("KvPair"),
      value(std::move(_value))
{
  this->_assignKey(_key);
}

ls_std::kv_key ls_std::KvPair::getKey()
{
  return this->key;
}

ls_std::kv_value ls_std::KvPair::getValue()
{
  return this->value;
}

void ls_std::KvPair::setValue(const ls_std::kv_value &_value)
{
  this->value = _value;
}

void ls_std::KvPair::_assignKey(const ls_std::kv_key &_key)
{
  if (_key.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->key = _key;
}
