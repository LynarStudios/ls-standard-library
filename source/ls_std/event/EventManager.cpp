/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/event/EventManager.hpp>
#include <ls_std/core/exception/EventNotSubscribedException.hpp>
#include <ls_std/core/exception/EventNotHandledException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::EventManager::EventManager() : ls::Class("EventManager")
{}

void ls::EventManager::subscribe(const ls::event_id &_id, const std::shared_ptr<ls::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
  else
  {
    throw ls::EventNotSubscribedException{};
  }
}

void ls::EventManager::unsubscribe(const ls::event_id &_id, const std::shared_ptr<ls::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->removeListener(_listener);
  }
}

bool ls::EventManager::addEventHandler(const std::shared_ptr<ls::EventHandler> &_eventHandler)
{
  bool wasAdded{};

  if (_eventHandler == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    std::pair<ls::event_id, std::shared_ptr<ls::EventHandler>> element = std::make_pair(_eventHandler->getId(), _eventHandler);
    wasAdded = this->eventHandlers.insert(element).second;
  }

  return wasAdded;
}

void ls::EventManager::fire(ls::Event _event)
{
  if (this->_hasEventHandler(_event.getId()))
  {
    this->eventHandlers.at(_event.getId())->tell(_event);
  }
  else
  {
    throw ls::EventNotHandledException{};
  }
}

bool ls::EventManager::hasEventHandler(const ls::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  return this->_hasEventHandler(_id);
}

bool ls::EventManager::removeEventHandler(const std::shared_ptr<ls::EventHandler> &_eventHandler)
{
  if (_eventHandler == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  return this->_removeEventHandler(_eventHandler);
}

bool ls::EventManager::_hasEventHandler(const ls::event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

bool ls::EventManager::_removeEventHandler(const std::shared_ptr<ls::EventHandler> &_eventHandler)
{
  return this->eventHandlers.erase(_eventHandler->getId()) == 1;
}
