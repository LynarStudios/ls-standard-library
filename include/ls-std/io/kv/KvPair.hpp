/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_KV_PAIR_HPP
#define LS_STD_KV_PAIR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/types/KvTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvPair : public ls::std::core::Class
  {
    public:

      explicit KvPair(const ls::std::core::type::kv_key &_key, ls::std::core::type::kv_value _value);
      ~KvPair() override;

      ls::std::core::type::kv_key getKey();
      ls::std::core::type::kv_value getValue();
      void setValue(const ls::std::core::type::kv_value &_value);

    private:

      ls::std::core::type::kv_key key{};
      ls::std::core::type::kv_value value{};

      void _assignKey(const ls::std::core::type::kv_key &_key);
  };
}

#endif