/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include <ls_std/base/Class.hpp>
#include "KVPair.hpp"
#include "KVTypes.hpp"
#include <map>

namespace ls_std
{
  class KVDocument : public ls_std::Class
  {
    public:

      KVDocument();
      ~KVDocument() override = default;

      bool addPair(ls_std::KVPair _pair);
      void clear();
      std::map<ls_std::kv_key, ls_std::KVPair> getPairs();
      bool hasPair(const ls_std::kv_key &_key);
      void removePair(const ls_std::kv_key &_key);

    private:

      std::map<ls_std::kv_key, ls_std::KVPair> pairs{};

      bool _hasPair(const ls_std::kv_key &_key);
  };
}

#endif
