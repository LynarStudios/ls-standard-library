/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-08
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/event/EventHandler.hpp>

ls::std::event::EventHandler::EventHandler(const ls::std::core::type::event_id &_id) : ls::std::event::Narrator()
{
  this->_assignId(_id);
}

ls::std::event::EventHandler::~EventHandler() = default;

ls::std::core::type::event_id ls::std::event::EventHandler::getId()
{
  return this->id;
}

void ls::std::event::EventHandler::_assignId(const ls::std::core::type::event_id &_id)
{
  ls::std::core::EmptyStringArgumentEvaluator{_id, "event manager id is empty!"}.evaluate();
  this->id = _id;
}
