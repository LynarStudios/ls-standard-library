/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_HPP

#include <memory>
#include "ls_std/lib/nlohmann_json/include/nlohmann/json.hpp"
#include "ls_std/logic/State.hpp"
#include "ls_std/serialization/ISerializable.hpp"
#include "ls_std/core/Class.hpp"

namespace ls
{
  class SerializableJsonState : public ls::std::core::Class, public ls::ISerializable
  {
    public:

      explicit SerializableJsonState(const ::std::shared_ptr<ls::State> &_value);
      ~SerializableJsonState() override = default;

      // implementation

      ls::std::core::byte_field marshal() override;
      void unmarshal(const ls::std::core::byte_field &_data) override;

      // additional functionality

      ::std::shared_ptr<ls::State> getValue();
      void setValue(const ::std::shared_ptr<ls::State> &_value);

    private:

      nlohmann::json jsonObject{};
      ::std::shared_ptr<ls::State> value{};

      void _assignValue(const ::std::shared_ptr<ls::State> &_value);
      void _clear();
      void _unmarshalStateConnections();
      void _update();
      void _updateStateConnections();
  };
}

#endif
