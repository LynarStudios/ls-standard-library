/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_EVENT_HPP
#define LS_STD_SERIALIZABLE_JSON_EVENT_HPP

#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/core/Class.hpp>
#include <ls_std/event/Event.hpp>
#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>

namespace ls_std
{
  class SerializableJsonEvent : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit SerializableJsonEvent(const std::shared_ptr<ls_std::Event> &_value);
      ~SerializableJsonEvent() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      std::shared_ptr<ls_std::Event> getValue();
      void setValue(const std::shared_ptr<ls_std::Event> &_value);

    private:

      nlohmann::json jsonObject{};
      std::shared_ptr<ls_std::Event> value{};

      void _assignValue(const std::shared_ptr<ls_std::Event> &_value);
      void _unmarshalParameterList();
      void _update();
      void _updateEventParameterList();
  };
}

#endif
