/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_EVENT_MANAGER_HPP
#define LS_STD_EVENT_MANAGER_HPP

#include <ls_std/core/Class.hpp>
#include <map>
#include <ls_std/core/types/EventTypes.hpp>
#include <memory>
#include "EventHandler.hpp"
#include <ls_std/core/interface/IEventSubscriber.hpp>

namespace ls
{
  namespace std
  {
    namespace event
    {
      class EventManager : public ls::std::core::Class, public ls::std::core::IEventSubscriber
      {
        public:

          explicit EventManager();
          ~EventManager() override = default;

          // implementation

          void subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::IListener> &_listener) override;
          void unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::IListener> &_listener) override;

          // additional functionality

          bool addEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler);
          void fire(ls::std::event::Event _event);
          bool hasEventHandler(const ls::std::core::type::event_id &_id);
          bool removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler);

        private:

          ::std::map<ls::std::core::type::event_id, ::std::shared_ptr<ls::std::event::EventHandler>> eventHandlers{};

          bool _hasEventHandler(const ls::std::core::type::event_id &_id);
          bool _removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler);
      };
    }
  }
}

#endif
