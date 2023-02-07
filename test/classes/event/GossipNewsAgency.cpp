/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-20
 *
 * */

#include "GossipNewsAgency.hpp"
#include "GossipNewsEvent.hpp"
#include <ls_std/ls_std_event.hpp>
#include <iostream>

ls_std_event_test::GossipNewsAgency::GossipNewsAgency(::std::string agencyName, EventManager eventManager)
  : NewsAgency(agencyName),
  m_eventManager(eventManager)
  {
  // subscribe listener at construction
    m_eventManager.subscribe(ls_std_event_test::GossipNewsEvent::EVENT_ID, )
  }

void ls_std_event_test::GossipNewsAgency::clear()
{
  this->news.clear();
}

::std::string ls_std_event_test::GossipNewsAgency::getNews()
{
  return this->news;
}

void ls_std_event_test::GossipNewsAgency::onGossipNews(ls_std_event_test::GossipNewsEvent event)
{
  ::std::cout << event.getParameterList().at("news");
}

ls_std_event_test::GossipNewsAgency::~GossipNewsAgency()
{
  //destructor should unsubscribe all methods to avoid nllptr when send Event
}
