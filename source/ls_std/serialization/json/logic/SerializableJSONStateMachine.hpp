/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_MACHINE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_MACHINE_HPP

#include "../../../../../include/ls_std/base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../../../include/ls_std/logic/StateMachine.hpp"
#include <memory>
#include <json.hpp>

namespace ls_std {
  class SerializableJSONStateMachine : public Class, public ISerializable {
    public:

      explicit SerializableJSONStateMachine(std::shared_ptr<StateMachine> _value);
      ~SerializableJSONStateMachine() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::StateMachine> value {};

      void _unmarshalCurrentState();
      void _unmarshalStates();
      void _update();
      void _updateCurrentState();
      void _updateStates();
  };
}

#endif
