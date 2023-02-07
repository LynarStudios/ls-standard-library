/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-01-06
 *
 * */

#ifndef LS_STD_EVENT_MANAGER_HPP
#define LS_STD_EVENT_MANAGER_HPP

#include <ls_std/core/Class.hpp>
#include <map>
#include <list>
#include <ls_std/event/types/EventTypes.hpp>
#include <memory>
#include <ls_std/event/interface/IEventManager.hpp>
#include <ls_std/os/dynamic_goal.hpp>
#include <functional>

using namespace ls::std::event;

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL EventManager : public ls::std::core::Class, public ls::std::event::interface_type::IEventManager
  {
    public:

      explicit EventManager();
      ~EventManager() override = default;

      // implementation

      void subscribe(const ls::std::event::type::event_id &_id, const ::std::function<void(ls::std::event::Event)>& _listener) override;
      void unsubscribe(const ls::std::event::type::event_id &_id, const ::std::function<void(ls::std::event::Event)>& _listener) override;

      // additional functionality

      void fire(ls::std::event::Event _event);

    private:

      ::std::map<ls::std::event::type::event_id, ::std::list<::std::function<void(Event)>>> eventHandler {};
  };
}

#endif
