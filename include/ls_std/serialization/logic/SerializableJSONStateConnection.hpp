/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>
#include <ls_std/base/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/logic/StateConnection.hpp>

namespace ls_std {
  class SerializableJSONStateConnection : public Class, public ISerializable {
    public:

      explicit SerializableJSONStateConnection(const std::shared_ptr<ls_std::StateConnection>& _value);
      ~SerializableJSONStateConnection() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      void setValue(const std::shared_ptr<ls_std::StateConnection>& _value);

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::StateConnection> value {};

      void _assignValue(const std::shared_ptr<ls_std::StateConnection>& _value);
      void _clear();
      void _update();
  };
}

#endif
