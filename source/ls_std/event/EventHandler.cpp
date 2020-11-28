/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-28
 *
 * */

#include <ls_std/event/EventHandler.hpp>

ls_std::EventHandler::EventHandler(ls_std::event_id  _id) : ls_std::Class("EventHandler"),
id(std::move(_id))
{}

void ls_std::EventHandler::addListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  if(!this->_hasListener(_listener)) {
    this->_addListener(_listener);
  }
}

ls_std::event_id ls_std::EventHandler::getId()
{
  return this->id;
}

void ls_std::EventHandler::notify(const ls_std::Event &_event)
{
  for(const auto& listener : this->listeners) {
    listener->listen(_event);
  }
}

void ls_std::EventHandler::removeListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  this->_removeListener(_listener);
}

void ls_std::EventHandler::_addListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  this->listeners.push_back(_listener);
}

bool ls_std::EventHandler::_hasListener(const std::shared_ptr<ls_std::IListener>& _listener)
{
  bool exists {};

  for(const auto& listener : this->listeners) {
    if(listener == _listener) {
      exists = true;
      break;
    }
  }

  return exists;
}

void ls_std::EventHandler::_removeListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  this->listeners.remove(_listener);
  this->listeners.size();
}
