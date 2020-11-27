/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-27
 *
 * */

#ifndef LS_STD_EVENT_MANAGER_HPP
#define LS_STD_EVENT_MANAGER_HPP

#include <ls_std/base/Class.hpp>
#include <map>
#include <ls_std/event/EventTypes.hpp>
#include <memory>
#include "EventHandler.hpp"

namespace ls_std {
  class EventManager : public ls_std::Class {
    public:

      explicit EventManager();
      ~EventManager() override = default;

      void addEventHandler(const std::shared_ptr<ls_std::EventHandler>& _eventHandler);
      void fire(ls_std::Event _event);
      void removeEventHandler(const std::shared_ptr<ls_std::EventHandler>& _eventHandler);

    private:

      std::map<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> eventHandlers {};

      bool _hasEventHandler(const ls_std::event_id& _id);
      void _removeEventHandler(const std::shared_ptr<ls_std::EventHandler>& _eventHandler);
  };
}

#endif
