/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include "GossipNewsEvent.hpp"

using ls::std::core::type::event_parameter;
using ls::std::event::Event;
using std::make_pair;
using std::string;
using test::event::GossipNewsEvent;

GossipNewsEvent::GossipNewsEvent(const string &_news) : Event("GossipNewsEvent")
{
  event_parameter newsParameter = make_pair("news", _news);
  this->addParameter(newsParameter);
}

GossipNewsEvent::~GossipNewsEvent() noexcept = default;
