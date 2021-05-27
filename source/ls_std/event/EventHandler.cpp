/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-27
 *
 * */

#include <ls_std/event/EventHandler.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::EventHandler::EventHandler(const ls_std::event_id& _id) : ls_std::Narrator()
{
  this->_assignId(_id);
}

ls_std::event_id ls_std::EventHandler::getId()
{
  return this->id;
}

void ls_std::EventHandler::_assignId(const ls_std::event_id &_id)
{
  if (_id.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->id = _id;
}
