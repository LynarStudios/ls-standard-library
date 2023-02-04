/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "IListener.hpp"
#include <ls-std/core/types/EventTypes.hpp>
#include <memory>

namespace ls::std::core::interface_type
{
  class IEventSubscriber
  {
    public:

      IEventSubscriber();
      ~IEventSubscriber();

      virtual void subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) = 0;
      virtual void unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) = 0;
  };
}

#endif
