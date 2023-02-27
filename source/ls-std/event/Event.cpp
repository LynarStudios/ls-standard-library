/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/event/Event.hpp>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::type::event_id;
using ls::std::core::type::event_parameter;
using ls::std::core::type::event_parameter_id;
using ls::std::core::type::event_parameter_list;
using ls::std::event::Event;

Event::Event(const event_id &_id) : Class("Event")
{
  this->_assignId(_id);
}

Event::~Event() noexcept = default;

bool Event::addParameter(const event_parameter &_eventParameter)
{
  bool wasAdded{};

  if (!this->_hasParameter(_eventParameter.first))
  {
    wasAdded = this->parameterList.insert(_eventParameter).second;
  }

  return wasAdded;
}

void Event::clearParameterList()
{
  this->parameterList.clear();
}

event_id Event::getId()
{
  return this->id;
}

event_parameter_list Event::getParameterList()
{
  return this->parameterList;
}

bool Event::removeParameter(const event_parameter_id &_id)
{
  return this->parameterList.erase(_id) == 1;
}

void Event::setId(const event_id &_id)
{
  this->_assignId(_id);
}

void Event::_assignId(const event_id &_id)
{
  EmptyStringArgumentEvaluator{_id, "event id is empty!"}.evaluate();
  this->id = _id;
}

bool Event::_hasParameter(const event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}
