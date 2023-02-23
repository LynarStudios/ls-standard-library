/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/EventNotHandledException.hpp>
#include <ls-std/core/exception/EventNotSubscribedException.hpp>
#include <ls-std/event/EventManager.hpp>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::EventNotHandledException;
using ls::std::core::EventNotSubscribedException;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::interface_type::IListener;
using ls::std::core::type::event_id;
using ls::std::event::Event;
using ls::std::event::EventHandler;
using ls::std::event::EventManager;
using std::make_pair;
using std::pair;
using std::shared_ptr;

EventManager::EventManager() : Class("EventManager")
{}

EventManager::~EventManager() noexcept = default;

void EventManager::subscribe(const event_id &_id, const shared_ptr<IListener> &_listener)
{
  EmptyStringArgumentEvaluator{_id, "event id is empty and can not be subscribed!"}.evaluate();
  NullPointerArgumentEvaluator{_listener, "listener reference for subscribe attempt is null!"}.evaluate();

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
  else
  {
    throw EventNotSubscribedException{"id: " + _id};
  }
}

void EventManager::unsubscribe(const event_id &_id, const shared_ptr<IListener> &_listener)
{
  EmptyStringArgumentEvaluator{_id, "event id is empty and can not be unsubscribed!"}.evaluate();
  NullPointerArgumentEvaluator{_listener, "listener reference for unsubscribe attempt is null!"}.evaluate();

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->removeListener(_listener);
  }
}

bool EventManager::addEventHandler(const shared_ptr<EventHandler> &_eventHandler)
{
  bool wasAdded{};
  NullPointerArgumentEvaluator{_eventHandler, "event handler reference for add attempt is null!"}.evaluate();

  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    pair<event_id, shared_ptr<EventHandler>> element = make_pair(_eventHandler->getId(), _eventHandler);
    wasAdded = this->eventHandlers.insert(element).second;
  }

  return wasAdded;
}

void EventManager::fire(Event _event)
{
  if (this->_hasEventHandler(_event.getId()))
  {
    this->eventHandlers.at(_event.getId())->tell(_event);
  }
  else
  {
    throw EventNotHandledException{"id: " + _event.getId()};
  }
}

bool EventManager::hasEventHandler(const event_id &_id)
{
  EmptyStringArgumentEvaluator{_id, "event id is empty and can not be passed!"}.evaluate();
  return this->_hasEventHandler(_id);
}

bool EventManager::removeEventHandler(const shared_ptr<EventHandler> &_eventHandler)
{
  NullPointerArgumentEvaluator{_eventHandler, "event handler reference for remove attempt is null!"}.evaluate();
  return this->_removeEventHandler(_eventHandler);
}

bool EventManager::_hasEventHandler(const event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

bool EventManager::_removeEventHandler(const shared_ptr<EventHandler> &_eventHandler)
{
  return this->eventHandlers.erase(_eventHandler->getId()) == 1;
}
