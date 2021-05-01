/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-01
 *
 * */

#include <ls_std/event/EventManager.hpp>

ls_std::EventManager::EventManager() : ls_std::Class("EventManager")
{}

void ls_std::EventManager::subscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->addListener(_listener);
  }
}

void ls_std::EventManager::unsubscribe(const ls_std::event_id &_id, const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (this->_hasEventHandler(_id))
  {
    this->eventHandlers.at(_id)->removeListener(_listener);
  }
}

void ls_std::EventManager::addEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  if (!this->_hasEventHandler(_eventHandler->getId()))
  {
    std::pair<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> element = std::make_pair(_eventHandler->getId(), _eventHandler);
    this->eventHandlers.insert(element);
  }
}

void ls_std::EventManager::fire(ls_std::Event _event)
{
  if (this->_hasEventHandler(_event.getId()))
  {
    this->eventHandlers.at(_event.getId())->tell(_event);
  }
}

void ls_std::EventManager::removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  this->_removeEventHandler(_eventHandler);
}

bool ls_std::EventManager::_hasEventHandler(const ls_std::event_id &_id)
{
  return this->eventHandlers.find(_id) != this->eventHandlers.end();
}

void ls_std::EventManager::_removeEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  this->eventHandlers.erase(_eventHandler->getId());
}
