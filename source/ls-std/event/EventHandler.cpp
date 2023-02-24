/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/event/EventHandler.hpp>

using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::type::event_id;
using ls::std::event::EventHandler;
using ls::std::event::Narrator;

EventHandler::EventHandler(const event_id &_id) : Narrator()
{
  this->_assignId(_id);
}

EventHandler::~EventHandler() noexcept = default;

event_id EventHandler::getId()
{
  return this->id;
}

void EventHandler::_assignId(const event_id &_id)
{
  EmptyStringArgumentEvaluator{_id, "event manager id is empty!"}.evaluate();
  this->id = _id;
}
