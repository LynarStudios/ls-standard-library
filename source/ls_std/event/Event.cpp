/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2020-11-29
 *
 * */

#include <ls_std/event/Event.hpp>

ls_std::Event::Event(ls_std::event_id _id) : ls_std::Class("Event"),
id(std::move(_id))
{}

void ls_std::Event::addParameter(const ls_std::event_parameter &_eventParameter)
{
  if(!this->_hasParameter(_eventParameter.first)) {
    this->parameterList.insert(_eventParameter);
  }
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

bool ls_std::Event::_hasParameter(const ls_std::event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}
