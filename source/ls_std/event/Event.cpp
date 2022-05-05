/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/event/Event.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::Event::Event(const ls::event_id &_id) : ls::Class("Event")
{
  this->_assignId(_id);
}

bool ls::Event::addParameter(const ls::event_parameter &_eventParameter)
{
  bool wasAdded{};

  if (!this->_hasParameter(_eventParameter.first))
  {
    wasAdded = this->parameterList.insert(_eventParameter).second;
  }

  return wasAdded;
}

void ls::Event::clearParameterList()
{
  this->parameterList.clear();
}

ls::event_id ls::Event::getId()
{
  return this->id;
}

ls::event_parameter_list ls::Event::getParameterList()
{
  return this->parameterList;
}

bool ls::Event::removeParameter(const ls::event_parameter_id &_id)
{
  return this->parameterList.erase(_id) == 1;
}

void ls::Event::setId(const ls::event_id &_id)
{
  this->_assignId(_id);
}

void ls::Event::_assignId(const ls::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->id = _id;
}

bool ls::Event::_hasParameter(const ls::event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}
