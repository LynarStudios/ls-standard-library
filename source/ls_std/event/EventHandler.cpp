/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-28
 *
 * */

#include <ls_std/event/EventHandler.hpp>

ls_std::EventHandler::EventHandler(ls_std::event_id  _id) : ls_std::Narrator(),
id(std::move(_id))
{}

ls_std::event_id ls_std::EventHandler::getId()
{
  return this->id;
}
