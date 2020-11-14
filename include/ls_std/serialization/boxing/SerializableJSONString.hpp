/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2020-11-14
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STRING_HPP
#define LS_STD_SERIALIZABLE_JSON_STRING_HPP

#include <memory>
#include <json.hpp>
#include "../../../../../include/ls_std/serialization/ISerializable.hpp"
#include "../../../../../include/ls_std/boxing/String.hpp"

namespace ls_std {
  class SerializableJSONString : public Class, public ISerializable {
    public:

      explicit SerializableJSONString(std::shared_ptr<ls_std::String> _value);
      ~SerializableJSONString() override = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::String> value {};

      void _update();
  };
}

#endif
