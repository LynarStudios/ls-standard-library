/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_EVENT_MANAGER_HPP
#define LS_STD_EVENT_MANAGER_HPP

#include <ls_std/core/Class.hpp>
#include <map>
#include <ls_std/event/EventTypes.hpp>
#include <memory>
#include "EventHandler.hpp"
#include "IEventSubscriber.hpp"

namespace ls
{
  class EventManager : public ls::Class, public ls::IEventSubscriber
  {
    public:

      explicit EventManager();
      ~EventManager() override = default;

      // implementation

      void subscribe(const ls::event_id &_id, const ::std::shared_ptr<ls::IListener> &_listener) override;
      void unsubscribe(const ls::event_id &_id, const ::std::shared_ptr<ls::IListener> &_listener) override;

      // additional functionality

      bool addEventHandler(const ::std::shared_ptr<ls::EventHandler> &_eventHandler);
      void fire(ls::Event _event);
      bool hasEventHandler(const ls::event_id &_id);
      bool removeEventHandler(const ::std::shared_ptr<ls::EventHandler> &_eventHandler);

    private:

      ::std::map<ls::event_id, ::std::shared_ptr<ls::EventHandler>> eventHandlers{};

      bool _hasEventHandler(const ls::event_id &_id);
      bool _removeEventHandler(const ::std::shared_ptr<ls::EventHandler> &_eventHandler);
  };
}

#endif
