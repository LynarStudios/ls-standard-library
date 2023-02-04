/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_GOSSIP_NEWS_EVENT_HPP
#define LS_STD_GOSSIP_NEWS_EVENT_HPP

#include <ls-std/ls-std-event.hpp>
#include <string>

namespace ls_std_event_test
{
  class GossipNewsEvent : public ls::std::event::Event
  {
    public:

      explicit GossipNewsEvent(const ::std::string &_news);
      ~GossipNewsEvent() override = default;
  };
}

#endif
