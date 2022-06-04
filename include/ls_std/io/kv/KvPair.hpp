/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_KV_PAIR_HPP
#define LS_STD_KV_PAIR_HPP

#include <ls_std/core/Class.hpp>
#include "ls_std/core/types/KvTypes.hpp"

namespace ls
{
  namespace std
  {
    namespace io
    {
      class KvPair : public ls::std::core::Class
      {
        public:

          explicit KvPair(const ls::std::core::type::kv_key &_key, ls::std::core::type::kv_value _value);
          ~KvPair() override = default;

          ls::std::core::type::kv_key getKey();
          ls::std::core::type::kv_value getValue();
          void setValue(const ls::std::core::type::kv_value &_value);

        private:

          ls::std::core::type::kv_key key{};
          ls::std::core::type::kv_value value{};

          void _assignKey(const ls::std::core::type::kv_key &_key);
      };
    }
  }
}

#endif
