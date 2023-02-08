/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-08
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include "IListener.hpp"
#include <ls-std/core/type/EventTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IEventSubscriber
  {
    public:

      IEventSubscriber();
      virtual ~IEventSubscriber();

      virtual void subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) = 0;
      virtual void unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) = 0;
  };
}

#endif
