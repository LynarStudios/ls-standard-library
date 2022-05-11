/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-11
 *
 * */

#include <ls_std/event/EventManager.hpp>
#include <ls_std/core/exception/EventNotSubscribedException.hpp>
#include <ls_std/core/exception/EventNotHandledException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::event::EventManager::EventManager() : ls::std::core::Class("EventManager")
{}

void ls::std::event::EventManager::subscribe(const ls::std::event::event_id &_id, const ::std::shared_ptr<ls::std::core::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
  else
  {
    throw ls::std::core::EventNotSubscribedException{};
  }
}

void ls::std::event::EventManager::unsubscribe(const ls::std::event::event_id &_id, const ::std::shared_ptr<ls::std::core::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->removeListener(_listener);
  }
}

bool ls::std::event::EventManager::addEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler)
{
  bool wasAdded{};

  if (_eventHandler == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    ::std::pair<ls::std::event::event_id, ::std::shared_ptr<ls::std::event::EventHandler>> element = ::std::make_pair(_eventHandler->getId(), _eventHandler);
    wasAdded = this->eventHandlers.insert(element).second;
  }

  return wasAdded;
}

void ls::std::event::EventManager::fire(ls::std::event::Event _event)
{
  if (this->_hasEventHandler(_event.getId()))
  {
    this->eventHandlers.at(_event.getId())->tell(_event);
  }
  else
  {
    throw ls::std::core::EventNotHandledException{};
  }
}

bool ls::std::event::EventManager::hasEventHandler(const ls::std::event::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  return this->_hasEventHandler(_id);
}

bool ls::std::event::EventManager::removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler)
{
  if (_eventHandler == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  return this->_removeEventHandler(_eventHandler);
}

bool ls::std::event::EventManager::_hasEventHandler(const ls::std::event::event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

bool ls::std::event::EventManager::_removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler)
{
  return this->eventHandlers.erase(_eventHandler->getId()) == 1;
}
