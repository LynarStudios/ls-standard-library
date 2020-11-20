/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-25
 * Changed:         2020-11-20
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_LONG_HPP
#define LS_STD_SERIALIZABLE_JSON_LONG_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/boxing/Long.hpp>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>

namespace ls_std {
  class SerializableJSONLong : public Class, public ISerializable {
    public:

      explicit SerializableJSONLong(std::shared_ptr<ls_std::Long> _value);
      ~SerializableJSONLong() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::Long> value {};

      void _update();
  };
}

#endif
