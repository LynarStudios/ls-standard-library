/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "GossipNewsEvent.hpp"

test::event::GossipNewsEvent::GossipNewsEvent(const ::std::string &_news) : ls::std::event::Event("GossipNewsEvent")
{
  ls::std::core::type::event_parameter newsParameter = ::std::make_pair("news", _news);
  this->addParameter(newsParameter);
}

test::event::GossipNewsEvent::~GossipNewsEvent() = default;
