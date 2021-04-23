/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/event/Event.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::Event::Event(const ls_std::event_id &_id) : ls_std::Class("Event")
{
  this->_assignId(_id);
}

ls_std::byte_field ls_std::Event::marshal()
{
  ls_std::byte_field data{};

  if (this->serializable != nullptr)
  {
    data = this->serializable->marshal();
  }

  return data;
}

void ls_std::Event::unmarshal(const ls_std::byte_field &_data)
{
  if (this->serializable != nullptr)
  {
    this->serializable->unmarshal(_data);
  }
}

void ls_std::Event::addParameter(const ls_std::event_parameter &_eventParameter)
{
  if (!this->_hasParameter(_eventParameter.first))
  {
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
  if (this->_hasParameter(_id))
  {
    this->parameterList.erase(_id);
  }
}

void ls_std::Event::setId(const ls_std::event_id &_id)
{
  this->_assignId(_id);
}

void ls_std::Event::_assignId(const ls_std::event_id &_id)
{
  if (_id.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->id = _id;
}

bool ls_std::Event::_hasParameter(const ls_std::event_id &_id)
{
  return this->parameterList.find(_id) != this->parameterList.end();
}

void ls_std::Event::setSerializable(std::shared_ptr<ISerializable> _serializable)
{
  this->serializable = std::move(_serializable);
}
