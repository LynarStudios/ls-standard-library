/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/event/Event.hpp>

ls::std::event::Event::Event(const ls::std::core::type::event_id &_id) : ls::std::core::Class("Event")
{
  this->_assignId(_id);
}

ls::std::event::Event::~Event() noexcept = default;

bool ls::std::event::Event::addParameter(const ls::std::core::type::event_parameter &_eventParameter)
{
  bool wasAdded{};

  if (!this->_hasParameter(_eventParameter.first))
  {
    wasAdded = this->parameterList.insert(_eventParameter).second;
  }

  return wasAdded;
}

void ls::std::event::Event::clearParameterList()
{
  this->parameterList.clear();
}

ls::std::core::type::event_id ls::std::event::Event::getId()
{
  return this->id;
}

ls::std::core::type::event_parameter_list ls::std::event::Event::getParameterList()
{
  return this->parameterList;
}

bool ls::std::event::Event::removeParameter(const ls::std::core::type::event_parameter_id &_id)
{
  return this->parameterList.erase(_id) == 1;
}

void ls::std::event::Event::setId(const ls::std::core::type::event_id &_id)
{
  this->_assignId(_id);
}

void ls::std::event::Event::_assignId(const ls::std::core::type::event_id &_id)
{
  ls::std::core::EmptyStringArgumentEvaluator{_id, "event id is empty!"}.evaluate();
  this->id = _id;
}

bool ls::std::event::Event::_hasParameter(const ls::std::core::type::event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}
