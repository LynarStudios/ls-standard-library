/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2020-12-20
 *
 * */

#include <ls_std/event/Event.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::Event::Event(ls_std::event_id _id) : ls_std::Class("Event")
{
  this->_assignId(std::move(_id));
}

void ls_std::Event::addParameter(const ls_std::event_parameter &_eventParameter)
{
  if(!this->_hasParameter(_eventParameter.first)) {
    this->parameterList.insert(_eventParameter);
  }
}

void ls_std::Event::clearParameterList()
{
  this->parameterList.clear();
}

ls_std::event_id ls_std::Event::getId()
{
  return this->id;
}

ls_std::event_parameter_list ls_std::Event::getParameterList()
{
  return this->parameterList;
}

void ls_std::Event::removeParameter(const ls_std::event_parameter_id &_id)
{
  if(this->_hasParameter(_id)) {
    this->parameterList.erase(_id);
  }
}

void ls_std::Event::setId(ls_std::event_id  _id)
{
  this->_assignId(std::move(_id));
}

void ls_std::Event::_assignId(ls_std::event_id _id)
{
  if(_id.empty()) {
    throw ls_std::IllegalArgumentException {};
  }

  this->id = _id;
}

bool ls_std::Event::_hasParameter(const ls_std::event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}
