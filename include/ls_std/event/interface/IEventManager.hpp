/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-01-06
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include <ls_std/event/types/EventTypes.hpp>
#include <ls_std/event/Event.hpp>
#include <memory>

namespace ls::std::event::interface_type
{
  class IEventManager
  {
    public:

      IEventManager() = default;
      ~IEventManager() = default;

      virtual void subscribe(const ls::std::event::type::event_id &_id, const ::std::function<void(ls::std::event::Event)>& listener) = 0;
      virtual void unsubscribe(const ls::std::event::type::event_id &_id, const ::std::function<void(ls::std::event::Event)>& listener) = 0;
  };
}

#endif
