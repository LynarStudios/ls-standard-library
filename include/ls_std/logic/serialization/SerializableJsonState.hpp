/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_HPP

#include <memory>
#include "ls_std/lib/nlohmann_json/include/nlohmann/json.hpp"
#include "ls_std/logic/State.hpp"
#include "ls_std/serialization/ISerializable.hpp"
#include "ls_std/core/Class.hpp"

namespace ls_std
{
  class SerializableJsonState : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit SerializableJsonState(const std::shared_ptr<ls_std::State> &_value);
      ~SerializableJsonState() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      std::shared_ptr<ls_std::State> getValue();
      void setValue(const std::shared_ptr<ls_std::State> &_value);

    private:

      nlohmann::json jsonObject{};
      std::shared_ptr<ls_std::State> value{};

      void _assignValue(const std::shared_ptr<ls_std::State> &_value);
      void _clear();
      void _unmarshalStateConnections();
      void _update();
      void _updateStateConnections();
  };
}

#endif
