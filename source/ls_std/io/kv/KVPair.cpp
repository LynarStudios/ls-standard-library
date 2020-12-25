/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2020-12-25
 *
 * */

#include <ls_std/io/kv/KVPair.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::KVPair::KVPair(const std::string& _key, std::string _value) : ls_std::Class("KVPair"),
value(std::move(_value))
{
  this->_assignKey(_key);
}

std::string ls_std::KVPair::getKey()
{
  return this->key;
}

std::string ls_std::KVPair::getValue()
{
  return this->value;
}

void ls_std::KVPair::setValue(const std::string &_value)
{
  this->value = _value;
}

void ls_std::KVPair::_assignKey(const std::string &_key)
{
  if(_key.empty()) {
    throw ls_std::IllegalArgumentException {};
  }

  this->key = _key;
}
