/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include "KvPair.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/types/KvTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <map>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvDocument : public ls::std::core::Class
  {
    public:

      KvDocument();
      ~KvDocument() override;

      bool addPair(ls::std::io::KvPair _pair);
      void clear();
      ::std::map<ls::std::core::type::kv_key, ls::std::io::KvPair> getPairs();
      bool hasPair(const ls::std::core::type::kv_key &_key);
      bool removePair(const ls::std::core::type::kv_key &_key);

    private:

      ::std::map<ls::std::core::type::kv_key, ls::std::io::KvPair> pairs{};

      bool _hasPair(const ls::std::core::type::kv_key &_key);
  };
}

#endif
