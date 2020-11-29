/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-29
 *
 * */

#ifndef LS_STD_GOSSIP_NEWS_AGENCY_HPP
#define LS_STD_GOSSIP_NEWS_AGENCY_HPP

#include <string>
#include <memory>
#include <map>
#include <ls_std/ls_std.hpp>
#include "NewsAgency.hpp"

namespace ls_std_test {
  class GossipNewsAgency : public ls_std_test::NewsAgency, public ls_std::IListener {
    public:

      GossipNewsAgency();
      ~GossipNewsAgency() override = default;

      // implementation

      void clear();
      std::string getNews();
      void listen(const ls_std::Class& _info) override;

      // additional functionality

      void addEventHandler(const std::shared_ptr<ls_std::EventHandler>& _eventHandler);

    private:

      std::map<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> eventHandlers {};
      std::string news {};
  };
}

#endif
