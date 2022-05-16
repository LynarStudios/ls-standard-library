/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-16
 *
 * */

#include <ls_std/core/utils/STLUtils.hpp>
#include <ls_std/event/Narrator.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::event::Narrator::Narrator() : ls::std::core::Class("Narrator")
{}

bool ls::std::event::Narrator::addListener(const ::std::shared_ptr<ls::std::core::interface::IListener> &_listener)
{
  bool wasAdded{};

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    if (!ls::std::core::STLUtils::contains(this->listeners, _listener))
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

std::list<std::shared_ptr<ls::std::core::interface::IListener>> ls::std::event::Narrator::getListeners()
{
  return this->listeners;
}

bool ls::std::event::Narrator::removeListener(const ::std::shared_ptr<ls::std::core::interface::IListener> &_listener)
{
  bool wasRemoved{};

  if (_listener == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    if (ls::std::core::STLUtils::contains(this->listeners, _listener))
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
