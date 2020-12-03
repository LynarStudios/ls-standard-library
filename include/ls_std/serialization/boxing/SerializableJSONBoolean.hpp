/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_BOOLEAN_HPP
#define LS_STD_SERIALIZABLE_JSON_BOOLEAN_HPP

#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>
#include <ls_std/base/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/boxing/Boolean.hpp>

namespace ls_std {
  class SerializableJSONBoolean : public Class, public ISerializable {
    public:

      explicit SerializableJSONBoolean(const std::shared_ptr<ls_std::Boolean>& _value);
      ~SerializableJSONBoolean() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      std::shared_ptr<ls_std::Boolean> getValue();
      void setValue(const std::shared_ptr<ls_std::Boolean>& _value);

    private:

      std::shared_ptr<ls_std::Boolean> value {};
      nlohmann::json jsonObject {};

      void _assignValue(const std::shared_ptr<ls_std::Boolean>& _value);
      void _update();
  };
}

#endif
