/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/event/EventHandler.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::event::EventHandler::EventHandler(const ls::std::event::event_id& _id) : ls::Narrator()
{
  this->_assignId(_id);
}

ls::std::event::event_id ls::std::event::EventHandler::getId()
{
  return this->id;
}

void ls::std::event::EventHandler::_assignId(const ls::std::event::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->id = _id;
}
