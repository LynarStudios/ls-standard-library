/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-08
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include "KvPair.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/type/KvTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <map>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvDocument : public ls::std::core::Class
  {
    public:

      KvDocument();
      ~KvDocument() override;

      bool addPair(ls::std::io::KvPair _pair); // nodiscard is optional here
      void clear();
      [[nodiscard]] ::std::map<ls::std::core::type::kv_key, ls::std::io::KvPair> getPairs();
      [[nodiscard]] bool hasPair(const ls::std::core::type::kv_key &_key);
      bool removePair(const ls::std::core::type::kv_key &_key); // nodiscard is optional here

    private:

      ::std::map<ls::std::core::type::kv_key, ls::std::io::KvPair> pairs{};

      [[nodiscard]] bool _hasPair(const ls::std::core::type::kv_key &_key);
  };
}

#endif
