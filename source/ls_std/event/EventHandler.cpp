/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/event/EventHandler.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::EventHandler::EventHandler(const ls::event_id& _id) : ls::Narrator()
{
  this->_assignId(_id);
}

ls::event_id ls::EventHandler::getId()
{
  return this->id;
}

void ls::EventHandler::_assignId(const ls::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::IllegalArgumentException{};
  }

  this->id = _id;
}
