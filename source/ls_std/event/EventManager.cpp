/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-27
 *
 * */

#include <ls_std/event/EventManager.hpp>
#include <ls_std/exception/EventNotSubscribedException.hpp>
#include <ls_std/exception/EventNotHandledException.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::EventManager::EventManager() : ls_std::Class("EventManager")
{}

void ls_std::EventManager::subscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
  else
  {
    throw ls_std::EventNotSubscribedException{};
  }
}

void ls_std::EventManager::unsubscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (_id.empty() || _listener == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->removeListener(_listener);
  }
}

bool ls_std::EventManager::addEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  bool wasAdded{};

  if (_eventHandler == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    std::pair<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> element = std::make_pair(_eventHandler->getId(), _eventHandler);
    wasAdded = this->eventHandlers.insert(element).second;
  }

  return wasAdded;
}

void ls_std::EventManager::fire(ls_std::Event _event)
{
  if (this->_hasEventHandler(_event.getId()))
  {
    this->eventHandlers.at(_event.getId())->tell(_event);
  }
  else
  {
    throw ls_std::EventNotHandledException{};
  }
}

bool ls_std::EventManager::hasEventHandler(const ls_std::event_id &_id)
{
  if (_id.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  return this->_hasEventHandler(_id);
}

bool ls_std::EventManager::removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  if (_eventHandler == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  return this->_removeEventHandler(_eventHandler);
}

bool ls_std::EventManager::_hasEventHandler(const ls_std::event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

bool ls_std::EventManager::_removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  return this->eventHandlers.erase(_eventHandler->getId()) == 1;
}
