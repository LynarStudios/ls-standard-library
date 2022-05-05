/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include <ls_std/core/Class.hpp>
#include "KvPair.hpp"
#include "KvTypes.hpp"
#include <map>

namespace ls
{
  class KvDocument : public ls::Class
  {
    public:

      KvDocument();
      ~KvDocument() override = default;

      bool addPair(ls::KvPair _pair);
      void clear();
      std::map<ls::kv_key, ls::KvPair> getPairs();
      bool hasPair(const ls::kv_key &_key);
      bool removePair(const ls::kv_key &_key);

    private:

      std::map<ls::kv_key, ls::KvPair> pairs{};

      bool _hasPair(const ls::kv_key &_key);
  };
}

#endif
