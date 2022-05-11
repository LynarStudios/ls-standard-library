/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "EventTypes.hpp"
#include <memory>
#include <ls_std/logic/IListener.hpp>

namespace ls
{
  namespace std
  {
    namespace event
    {
      class IEventSubscriber
      {
        public:

          IEventSubscriber() = default;
          ~IEventSubscriber() = default;

          virtual void subscribe(const ls::std::event::event_id &_id, const ::std::shared_ptr<ls::std::logic::IListener> &_listener) = 0;
          virtual void unsubscribe(const ls::std::event::event_id &_id, const ::std::shared_ptr<ls::std::logic::IListener> &_listener) = 0;
      };
    }
  }
}

#endif
