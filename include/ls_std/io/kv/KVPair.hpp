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
#include <string>

namespace ls_std {
  class KVPair : public ls_std::Class {
    public:

      explicit KVPair(const std::string& _key, std::string _value);
      ~KVPair() override = default;

      std::string getKey();
      std::string getValue();
      void setValue(const std::string& _value);

    private:

      std::string key {};
      std::string value {};

      void _assignKey(const std::string& _key);
  };
}

#endif
