/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2020-09-14
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP

#include "../../../base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../logic/StateConnection.hpp"
#include <memory>
#include <json.hpp>

namespace ls_std {
  class SerializableJSONStateConnection : public Class, public ISerializable {
    public:

      SerializableJSONStateConnection(std::shared_ptr<ls_std::StateConnection> _value);
      ~SerializableJSONStateConnection() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      std::shared_ptr<ls_std::StateConnection> value {};
      nlohmann::json jsonObject {};

      void _update();
  };
}

#endif
