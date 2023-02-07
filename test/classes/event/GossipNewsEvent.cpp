/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-20
 *
 * */

#include "GossipNewsEvent.hpp"

const std::string ls_std_event_test::GossipNewsEvent::EVENT_ID = std::string("GossipNewsEvent");

ls_std_event_test::GossipNewsEvent::GossipNewsEvent(const ::std::string &_news) : ls::std::event::Event(EVENT_ID)
{
  ls::std::event::type::event_parameter newsParameter = ::std::make_pair("news", _news);
  this->addParameter(newsParameter);
}
