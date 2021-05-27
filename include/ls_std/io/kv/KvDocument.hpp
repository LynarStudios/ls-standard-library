/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_KV_DOCUMENT_HPP
#define LS_STD_KV_DOCUMENT_HPP

#include <ls_std/base/Class.hpp>
#include "KvPair.hpp"
#include "KvTypes.hpp"
#include <map>

namespace ls_std
{
  class KvDocument : public ls_std::Class
  {
    public:

      KvDocument();
      ~KvDocument() override = default;

      bool addPair(ls_std::KvPair _pair);
      void clear();
      std::map<ls_std::kv_key, ls_std::KvPair> getPairs();
      bool hasPair(const ls_std::kv_key &_key);
      void removePair(const ls_std::kv_key &_key);

    private:

      std::map<ls_std::kv_key, ls_std::KvPair> pairs{};

      bool _hasPair(const ls_std::kv_key &_key);
  };
}

#endif
