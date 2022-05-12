/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-12
 *
 * */

#include <ls_std/event/EventHandler.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::event::EventHandler::EventHandler(const ls::std::core::type::event_id& _id) : ls::std::logic::Narrator()
{
  this->_assignId(_id);
}

ls::std::core::type::event_id ls::std::event::EventHandler::getId()
{
  return this->id;
}

void ls::std::event::EventHandler::_assignId(const ls::std::core::type::event_id &_id)
{
  if (_id.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->id = _id;
}
