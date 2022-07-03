/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/io/kv/KvPair.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::io::KvPair::KvPair(const ls::std::core::type::kv_key &_key, ls::std::core::type::kv_value _value)
    : ls::std::core::Class("KvPair"),
      value(::std::move(_value))
{
  this->_assignKey(_key);
}

ls::std::core::type::kv_key ls::std::io::KvPair::getKey()
{
  return this->key;
}

ls::std::core::type::kv_value ls::std::io::KvPair::getValue()
{
  return this->value;
}

void ls::std::io::KvPair::setValue(const ls::std::core::type::kv_value &_value)
{
  this->value = _value;
}

void ls::std::io::KvPair::_assignKey(const ls::std::core::type::kv_key &_key)
{
  if (_key.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->key = _key;
}