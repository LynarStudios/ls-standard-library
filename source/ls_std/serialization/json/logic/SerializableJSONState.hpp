/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2020-10-29
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_HPP

#include "../../../base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../logic/State.hpp"
#include <memory>
#include <json.hpp>

namespace ls_std {
  class SerializableJSONState : public Class, public ISerializable {
    public:

      explicit SerializableJSONState(std::shared_ptr<State> _value);
      ~SerializableJSONState() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      void setValue(std::shared_ptr<State> _value);

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::State> value {};

      void _clear();
      void _unmarshalExistingStateConnection(nlohmann::json _jsonObject);
      void _unmarshalNewStateConnection(nlohmann::json _jsonObject);
      void _unmarshalStateConnections();
      void _update();
      void _updateStateConnections();
  };
}

#endif