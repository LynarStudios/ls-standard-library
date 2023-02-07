/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-20
 *
 * */

#ifndef LS_STD_GOSSIP_NEWS_AGENCY_HPP
#define LS_STD_GOSSIP_NEWS_AGENCY_HPP

#include <string>
#include <memory>
#include <map>
#include <ls_std/ls_std_core.hpp>
#include <ls_std/ls_std_event.hpp>
#include "NewsAgency.hpp"
#include "GossipNewsEvent.hpp"

using ls::std::event::interface_type::IEventManager;

namespace ls_std_event_test
{
  class GossipNewsAgency : public ls_std_event_test::NewsAgency
  {
    public:

      GossipNewsAgency(::std::string agencyName, EventManager eventManager);
      ~GossipNewsAgency();

      // implementation

      void onGossipNews(ls_std_event_test::GossipNewsEvent event);

      // additional functionality

      void clear();
      ::std::string getNews();

    private:

      EventManager m_eventManager;
      ::std::string news{};
  };
}

#endif
