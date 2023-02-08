/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/EventNotHandledException.hpp>
#include <ls-std/core/exception/EventNotSubscribedException.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/event/EventManager.hpp>

ls::std::event::EventManager::EventManager() : ls::std::core::Class("EventManager")
{}

ls::std::event::EventManager::~EventManager() = default;

void ls::std::event::EventManager::subscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener)
{
  ls::std::core::EmptyStringArgumentEvaluator{_id, "event id is empty and can not be subscribed!"}.evaluate();

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{"_listener is null"};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
  else
  {
    throw ls::std::core::EventNotSubscribedException{"id: " + _id};
  }
}

void ls::std::event::EventManager::unsubscribe(const ls::std::core::type::event_id &_id, const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener)
{
  ls::std::core::EmptyStringArgumentEvaluator{_id, "event id is empty and can not be unsubscribed!"}.evaluate();

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{"_listener is null"};
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
    throw ls::std::core::IllegalArgumentException{"_eventHandler is null"};
  }

  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    ::std::pair<ls::std::core::type::event_id, ::std::shared_ptr<ls::std::event::EventHandler>> element = ::std::make_pair(_eventHandler->getId(), _eventHandler);
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
    throw ls::std::core::EventNotHandledException{"id: " + _event.getId()};
  }
}

bool ls::std::event::EventManager::hasEventHandler(const ls::std::core::type::event_id &_id)
{
  ls::std::core::EmptyStringArgumentEvaluator{_id, "event id is empty and can not be passed!"}.evaluate();
  return this->_hasEventHandler(_id);
}

bool ls::std::event::EventManager::removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler)
{
  if (_eventHandler == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{"_eventHandler is null"};
  }

  return this->_removeEventHandler(_eventHandler);
}

bool ls::std::event::EventManager::_hasEventHandler(const ls::std::core::type::event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

bool ls::std::event::EventManager::_removeEventHandler(const ::std::shared_ptr<ls::std::event::EventHandler> &_eventHandler)
{
  return this->eventHandlers.erase(_eventHandler->getId()) == 1;
}
