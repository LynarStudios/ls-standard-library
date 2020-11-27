/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-27
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "EventTypes.hpp"

namespace ls_std {
  class IEventSubscriber {
    public:

      IEventSubscriber() = default;
      ~IEventSubscriber() = default;

      virtual void subscribe(const ls_std::event_id& _id) = 0;
      virtual void unsubscribe(const ls_std::event_id& _id) = 0;
  };
}

#endif
