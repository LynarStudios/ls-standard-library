/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_KV_PAIR_HPP
#define LS_STD_KV_PAIR_HPP

#include <ls_std/core/Class.hpp>
#include "KvTypes.hpp"

namespace ls
{
  class KvPair : public ls::std::core::Class
  {
    public:

      explicit KvPair(const ls::kv_key &_key, ls::kv_value _value);
      ~KvPair() override = default;

      ls::kv_key getKey();
      ls::kv_value getValue();
      void setValue(const ls::kv_value &_value);

    private:

      ls::kv_key key{};
      ls::kv_value value{};

      void _assignKey(const ls::kv_key &_key);
  };
}

#endif
