/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-07
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_EVENT_HPP
#define LS_STD_SERIALIZABLE_JSON_EVENT_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/core/types/Types.hpp>
#include <ls-std/event/Event.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL SerializableJsonEvent : public ls::std::core::Class, public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit SerializableJsonEvent(const ::std::shared_ptr<ls::std::event::Event> &_value);
      ~SerializableJsonEvent() override;

      // implementation

      ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

      // additional functionality

      ::std::shared_ptr<ls::std::event::Event> getValue();
      void setValue(const ::std::shared_ptr<ls::std::event::Event> &_value);

    private:

      ls::std::core::type::json jsonObject{};
      ::std::shared_ptr<ls::std::event::Event> value{};

      void _assignValue(const ::std::shared_ptr<ls::std::event::Event> &_value);
      void _unmarshalParameterList();
      void _update();
      void _updateEventParameterList();
  };
}

#endif
