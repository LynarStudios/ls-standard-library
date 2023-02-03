/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_EVENT_MANAGER_HPP
#define LS_STD_EVENT_MANAGER_HPP

#include "EventHandler.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IEventSubscriber.hpp>
#include <ls-std/core/types/EventTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <map>
#include <memory>

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL EventManager : public ls::std::core::Class, public ls::std::core::interface_type::IEventSubscriber
  {
    public:

      explicit EventManager();
      ~EventManager() override = default;

      // implementation

      void subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) override;
      void unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener) override;

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

#endif
