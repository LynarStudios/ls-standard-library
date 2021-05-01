/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "EventTypes.hpp"
#include <memory>
#include <ls_std/logic/IListener.hpp>

namespace ls_std
{
  class IEventSubscriber
  {
    public:

      IEventSubscriber() = default;
      ~IEventSubscriber() = default;

      virtual void subscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener) = 0;
      virtual void unsubscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener) = 0;
  };
}

#endif
