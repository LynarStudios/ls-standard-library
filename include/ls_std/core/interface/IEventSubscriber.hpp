/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-16
 *
 * */

#ifndef LS_STD_I_EVENT_SUBSCRIBER_HPP
#define LS_STD_I_EVENT_SUBSCRIBER_HPP

#include <ls_std/core/types/EventTypes.hpp>
#include <memory>
#include "IListener.hpp"

namespace ls
{
  namespace std
  {
    namespace core
    {
      namespace interface
      {
        class IEventSubscriber
        {
          public:

            IEventSubscriber() = default;
            ~IEventSubscriber() = default;

            virtual void subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface::IListener> &_listener) = 0;
            virtual void unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface::IListener> &_listener) = 0;
        };
      }
    }
  }
}

#endif
