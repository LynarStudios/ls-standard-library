/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "EventTypes.hpp"
#include <memory>
#include <ls_std/logic/IListener.hpp>

namespace ls
{
  class IEventSubscriber
  {
    public:

      IEventSubscriber() = default;
      ~IEventSubscriber() = default;

      virtual void subscribe(const ls::event_id &_id, const std::shared_ptr<ls::IListener> &_listener) = 0;
      virtual void unsubscribe(const ls::event_id &_id, const std::shared_ptr<ls::IListener> &_listener) = 0;
  };
}

#endif
