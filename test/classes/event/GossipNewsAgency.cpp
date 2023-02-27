/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include "GossipNewsAgency.hpp"
#include <ls-std/ls-std-event.hpp>

using ls::std::core::Class;
using ls::std::event::Event;
using std::string;
using test::event::GossipNewsAgency;
using test::event::NewsAgency;

GossipNewsAgency::GossipNewsAgency() : NewsAgency("GossipNewsAgency")
{}

GossipNewsAgency::~GossipNewsAgency() noexcept = default;

void GossipNewsAgency::listen(const Class &_info)
{
  Event event = dynamic_cast<const Event &>(_info);

  if (event.getId() == "SeriousNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }

  if (event.getId() == "GossipNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void GossipNewsAgency::clear()
{
  this->news.clear();
}

string GossipNewsAgency::getNews()
{
  return this->news;
}
