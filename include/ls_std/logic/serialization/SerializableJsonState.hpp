/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-15
 * Changed:         2022-07-01
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_HPP

#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>
#include <ls_std/logic/State.hpp>
#include <ls_std/core/interface/ISerializable.hpp>
#include <ls_std/core/Class.hpp>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class DYNAMIC_GOAL SerializableJsonState : public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
      {
        public:

          explicit SerializableJsonState(const ::std::shared_ptr<ls::std::logic::State> &_value);
          ~SerializableJsonState() override = default;

          // implementation

          ls::std::core::type::byte_field marshal() override;
          void unmarshal(const ls::std::core::type::byte_field &_data) override;

          // additional functionality

          ::std::shared_ptr<ls::std::logic::State> getValue();
          void setValue(const ::std::shared_ptr<ls::std::logic::State> &_value);

        private:

          nlohmann::json jsonObject{};
          ::std::shared_ptr<ls::std::logic::State> value{};

          void _assignValue(const ::std::shared_ptr<ls::std::logic::State> &_value);
          void _clear();
          void _unmarshalStateConnections();
          void _update();
          void _updateStateConnections();
      };
    }
  }
}

#endif
