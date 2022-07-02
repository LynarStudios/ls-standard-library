/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include <ls_std/core/Class.hpp>
#include "KvPair.hpp"
#include <ls_std/core/types/KvTypes.hpp>
#include <map>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::io
{
  class DYNAMIC_GOAL KvDocument : public ls::std::core::Class
  {
    public:

      KvDocument();
      ~KvDocument() override = default;

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
