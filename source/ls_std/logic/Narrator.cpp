/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/utils/STLUtils.hpp>
#include <ls_std/logic/Narrator.hpp>

ls_std::Narrator::Narrator() : ls_std::Class("Narrator")
{}

void ls_std::Narrator::addListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (!ls_std::STLUtils::contains(this->listeners, _listener))
  {
    this->listeners.push_back(_listener);
  }
}

void ls_std::Narrator::clear()
{
  this->listeners.clear();
}

std::list<std::shared_ptr<ls_std::IListener>> ls_std::Narrator::getListeners()
{
  return this->listeners;
}

void ls_std::Narrator::removeListener(const std::shared_ptr<ls_std::IListener> &_listener)
{
  if (ls_std::STLUtils::contains(this->listeners, _listener))
  {
    this->listeners.remove(_listener);
  }
}

void ls_std::Narrator::tell(const ls_std::Class &_info)
{
  for (const auto &listener : this->listeners)
  {
    listener->listen(_info);
  }
}
