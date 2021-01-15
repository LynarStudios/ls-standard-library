/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-27
 *
 * */

#ifndef LS_STD_GOSSIP_NEWS_EVENT_HPP
#define LS_STD_GOSSIP_NEWS_EVENT_HPP

#include <ls_std/ls_std.hpp>
#include <string>

namespace ls_std_test {
  class GossipNewsEvent : public ls_std::Event {
    public:

      explicit GossipNewsEvent(const std::string& _news);
      ~GossipNewsEvent() override = default;
  };
}

#endif