/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-07-03
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP

#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>
#include <ls_std/core/Class.hpp>
#include <ls_std/core/interface/ISerializable.hpp>
#include <ls_std/logic/StateConnection.hpp>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class LS_STD_DYNAMIC_GOAL SerializableJsonStateConnection : public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
      {
        public:

          explicit SerializableJsonStateConnection(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value);
          ~SerializableJsonStateConnection() override = default;

          // implementation

          ls::std::core::type::byte_field marshal() override;
          void unmarshal(const ls::std::core::type::byte_field &_data) override;

          // additional functionality

          ::std::shared_ptr<ls::std::logic::StateConnection> getValue();
          void setValue(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value);

        private:

          nlohmann::json jsonObject{};
          ::std::shared_ptr<ls::std::logic::StateConnection> value{};

          void _assignValue(const ::std::shared_ptr<ls::std::logic::StateConnection> &_value);
          void _clear();
          void _update();
      };
    }
  }
}

#endif
