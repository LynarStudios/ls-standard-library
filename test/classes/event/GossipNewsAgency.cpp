/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-08
 *
 * */

#include "GossipNewsAgency.hpp"

ls_std_test::GossipNewsAgency::GossipNewsAgency() : ls_std_test::NewsAgency("GossipNewsAgency")
{}

void ls_std_test::GossipNewsAgency::listen(const ls::Class &_info)
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

void ls_std_test::GossipNewsAgency::clear()
{
  this->news.clear();
}

std::string ls_std_test::GossipNewsAgency::getNews()
{
  return this->news;
}
