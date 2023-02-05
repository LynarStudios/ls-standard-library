/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "GossipNewsEvent.hpp"

ls_std_event_test::GossipNewsEvent::GossipNewsEvent(const ::std::string &_news) : ls::std::event::Event("GossipNewsEvent")
{
  ls::std::core::type::event_parameter newsParameter = ::std::make_pair("news", _news);
  this->addParameter(newsParameter);
}

ls_std_event_test::GossipNewsEvent::~GossipNewsEvent() = default;
