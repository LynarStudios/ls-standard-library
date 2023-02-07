/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-01-06
 *
 * */

#include <ls_std/event/EventManager.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <iostream>
#include <list>

ls::std::event::EventManager::EventManager() : ls::std::core::Class("EventManager")
{}

void ls::std::event::EventManager::subscribe(const ls::std::event::type::event_id &_id,
                                             const ::std::function<void(ls::std::event::Event)>& _listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  ::std::list<::std::function<void(Event)>> listeners = this->eventHandler.at(_id);
  if (!listeners.empty()) //null check needed?
  {
    listeners.push_back(_listener);
  }
}

void ls::std::event::EventManager::unsubscribe(const ls::std::event::type::event_id &_id,
                                               const ::std::function<void(ls::std::event::Event)> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  ::std::list<::std::function<void(Event)>> listeners = this->eventHandler.at(_id);
  //listeners.remove(_listener);
}

void ls::std::event::EventManager::fire(ls::std::event::Event _event)
{
  ::std::list<::std::function<void(Event)>> listeners = this->eventHandler.at(_event.getId());

  if (!listeners.empty())
  {
    for (::std::function<void(Event)> &listener : listeners)
    {
      listener(_event);
    }
  }
}