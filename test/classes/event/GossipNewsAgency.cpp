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

test::event::GossipNewsAgency::GossipNewsAgency() : test::event::NewsAgency("GossipNewsAgency")
{}

test::event::GossipNewsAgency::~GossipNewsAgency() = default;

void test::event::GossipNewsAgency::listen(const ls::std::core::Class &_info)
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

void test::event::GossipNewsAgency::clear()
{
  this->news.clear();
}

::std::string test::event::GossipNewsAgency::getNews()
{
  return this->news;
}
