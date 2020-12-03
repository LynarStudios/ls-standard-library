/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_MACHINE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_MACHINE_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/logic/StateMachine.hpp>
#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>

namespace ls_std {
  class SerializableJSONStateMachine : public Class, public ISerializable {
    public:

      explicit SerializableJSONStateMachine(const std::shared_ptr<ls_std::StateMachine>& _value);
      ~SerializableJSONStateMachine() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      std::shared_ptr<ls_std::StateMachine> getValue();
      void setValue(const std::shared_ptr<ls_std::StateMachine>& _value);

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::StateMachine> value {};

      void _assignValue(const std::shared_ptr<ls_std::StateMachine>& _value);
      void _unmarshalCurrentState();
      void _unmarshalStates();
      void _update();
      void _updateCurrentState();
      void _updateStates();
  };
}

#endif
