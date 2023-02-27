/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-23
 *
 * */

#include <algorithm>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/event/Narrator.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::interface_type::IListener;
using ls::std::event::Narrator;
using std::find;
using std::list;
using std::shared_ptr;

Narrator::Narrator() : Class("Narrator")
{}

Narrator::~Narrator() noexcept = default;

bool Narrator::addListener(const shared_ptr<IListener> &_listener)
{
  bool wasAdded{};
  NullPointerArgumentEvaluator{_listener, "listener reference for add attempt is null!"}.evaluate();

  if (!this->_hasListener(_listener))
  {
    this->listeners.push_back(_listener);
    wasAdded = true;
  }

  return wasAdded;
}

void Narrator::clear()
{
  this->listeners.clear();
}

list<shared_ptr<IListener>> Narrator::getListeners()
{
  return this->listeners;
}

bool Narrator::removeListener(const shared_ptr<IListener> &_listener)
{
  bool wasRemoved{};
  NullPointerArgumentEvaluator{_listener, "listener reference for remove attempt is null!"}.evaluate();

  if (this->_hasListener(_listener))
  {
    this->listeners.remove(_listener);
    wasRemoved = true;
  }

  return wasRemoved;
}

void Narrator::tell(const Class &_info)
{
  for (const auto &listener : this->listeners)
  {
    listener->listen(_info);
  }
}

bool Narrator::_hasListener(const shared_ptr<IListener> &_listener)
{
  return find(this->listeners.begin(), this->listeners.end(), _listener) != this->listeners.end();
}
