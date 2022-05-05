/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/core/utils/STLUtils.hpp>
#include <ls_std/logic/Narrator.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls_std::Narrator::Narrator() : ls_std::Class("Narrator")
{}

bool ls_std::Narrator::addListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  bool wasAdded{};

  if (_listener == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
  else
  {
    if (!ls_std::STLUtils::contains(this->listeners, _listener))
    {
      this->listeners.push_back(_listener);
      wasAdded = true;
    }
  }

  return wasAdded;
}

void ls_std::Narrator::clear()
{
  this->listeners.clear();
}

std::list<std::shared_ptr<ls_std::IListener>> ls_std::Narrator::getListeners()
{
  return this->listeners;
}

bool ls_std::Narrator::removeListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  bool wasRemoved{};

  if (_listener == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
  else
  {
    if (ls_std::STLUtils::contains(this->listeners, _listener))
    {
      this->listeners.remove(_listener);
      wasRemoved = true;
    }
  }

  return wasRemoved;
}

void ls_std::Narrator::tell(const ls_std::Class &_info)
{
  for (const auto &listener : this->listeners)
  {
    listener->listen(_info);
  }
}
