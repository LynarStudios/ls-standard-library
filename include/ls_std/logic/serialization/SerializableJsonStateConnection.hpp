/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-14
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP
#define LS_STD_SERIALIZABLE_JSON_STATE_CONNECTION_HPP

#include <memory>
#include "ls_std/lib/nlohmann_json/include/nlohmann/json.hpp"
#include "ls_std/core/Class.hpp"
#include "ls_std/serialization/ISerializable.hpp"
#include "ls_std/logic/StateConnection.hpp"

namespace ls
{
  class SerializableJsonStateConnection : public ls::Class, public ls::ISerializable
  {
    public:

      explicit SerializableJsonStateConnection(const std::shared_ptr<ls::StateConnection> &_value);
      ~SerializableJsonStateConnection() override = default;

      // implementation

      ls::byte_field marshal() override;
      void unmarshal(const ls::byte_field &_data) override;

      // additional functionality

      std::shared_ptr<ls::StateConnection> getValue();
      void setValue(const std::shared_ptr<ls::StateConnection> &_value);

    private:

      nlohmann::json jsonObject{};
      std::shared_ptr<ls::StateConnection> value{};

      void _assignValue(const std::shared_ptr<ls::StateConnection> &_value);
      void _clear();
      void _update();
  };
}

#endif
