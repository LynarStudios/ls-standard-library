/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-06
 *
 * */

#include <algorithm>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/event/Narrator.hpp>

ls::std::event::Narrator::Narrator() : ls::std::core::Class("Narrator")
{}

ls::std::event::Narrator::~Narrator() = default;

bool ls::std::event::Narrator::addListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener)
{
  bool wasAdded{};

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    if (!this->_hasListener(_listener))
    {
      this->listeners.push_back(_listener);
      wasAdded = true;
    }
  }

  return wasAdded;
}

void ls::std::event::Narrator::clear()
{
  this->listeners.clear();
}

::std::list<::std::shared_ptr<ls::std::core::interface_type::IListener>> ls::std::event::Narrator::getListeners()
{
  return this->listeners;
}

bool ls::std::event::Narrator::removeListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener)
{
  bool wasRemoved{};

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    if (this->_hasListener(_listener))
    {
      this->listeners.remove(_listener);
      wasRemoved = true;
    }
  }

  return wasRemoved;
}

void ls::std::event::Narrator::tell(const ls::std::core::Class &_info)
{
  for (const auto &listener : this->listeners)
  {
    listener->listen(_info);
  }
}

bool ls::std::event::Narrator::_hasListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener)
{
  return ::std::find(this->listeners.begin(), this->listeners.end(), _listener) != this->listeners.end();
}