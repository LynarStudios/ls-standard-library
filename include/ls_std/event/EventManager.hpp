/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-04-29
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

namespace ls_std
{
  class EventManager : public ls_std::Class, public ls_std::IEventSubscriber
  {
    public:

      explicit EventManager();
      ~EventManager() override = default;

      // implementation

      void subscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener) override;
      void unsubscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener) override;

      // additional functionality

      bool addEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler);
      void fire(ls_std::Event _event);
      bool hasEventHandler(const ls_std::event_id &_id);
      bool removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler);

    private:

      std::map<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> eventHandlers{};

      bool _hasEventHandler(const ls_std::event_id &_id);
      bool _removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler);
  };
}

#endif
