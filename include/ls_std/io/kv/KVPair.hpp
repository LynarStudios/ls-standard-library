/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2020-12-25
 *
 * */

#ifndef LS_STD_KV_PAIR_HPP
#define LS_STD_KV_PAIR_HPP

#include <ls_std/base/Class.hpp>
#include "KVTypes.hpp"

namespace ls_std {
  class KVPair : public ls_std::Class {
    public:

      explicit KVPair(const ls_std::kv_key& _key, ls_std::kv_value _value);
      ~KVPair() override = default;

      ls_std::kv_key getKey();
      ls_std::kv_value getValue();
      void setValue(const ls_std::kv_value& _value);

    private:

      ls_std::kv_key key {};
      ls_std::kv_value value {};

      void _assignKey(const ls_std::kv_key& _key);
  };
}

#endif
