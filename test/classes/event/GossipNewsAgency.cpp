/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "GossipNewsAgency.hpp"
#include <ls-std/ls-std-event.hpp>

ls_std_event_test::GossipNewsAgency::GossipNewsAgency() : ls_std_event_test::NewsAgency("GossipNewsAgency")
{}

ls_std_event_test::GossipNewsAgency::~GossipNewsAgency() = default;

void ls_std_event_test::GossipNewsAgency::listen(const ls::std::core::Class &_info)
{
  ls::std::event::Event event = dynamic_cast<const ls::std::event::Event &>(_info);

  if (event.getId() == "SeriousNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }

  if (event.getId() == "GossipNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void ls_std_event_test::GossipNewsAgency::clear()
{
  this->news.clear();
}

::std::string ls_std_event_test::GossipNewsAgency::getNews()
{
  return this->news;
}
